//Writes a character to display.
void output_char(char c) {
  asm volatile ( //This instruction writes a value to a CSR register. This is a custom register and I have modified Spike to print whatever character is written to this CSR. This is my way of printing without requiring the support of a kernel or the RISC-V front end server.
    "csrrw zero, 0x404, %0" //CSRRW rd, csr, rs1
    : //output operands
    : "r"(c) //input operands
    : //clobbered registers
  );
}

//Calls output_char in a loop.
void output_string(char *s) {
  int i = 0;
  while(s[i] != '\0') {
    output_char(s[i]);
    i++;
  }
}

int main() {
  int id = -1;
  asm volatile( //This function reads out a system register and put the ID of the core into the id variable
    "csrrs %0, 0xF14, zero" //CSSRS rd, mhartid, 0
    : "=r"(id) //output
    : //input
    : //clobbered
  );

  char outString[16] = "Core  \n"; //This is the output string we will use.
  char idChar = id + '0'; //We add '0' to the id to convert the core ID to an ASCII code.
  outString[5] = idChar; //Set the second space to the idChar
  output_string(outString); //Output the string.
  return 0;
}

