#include <iostream>

using Byte = unsigned char;
using Word = unsigned short;
using u32 = unsigned int;

struct Mem
{
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte Data[MAX_MEM];
    void Initialize();
};

void Mem::Initialize()
{
    for(u32 i = 0; i < MAX_MEM; ++i)
    {
        Data[i] = 0;
    }
}

struct CPU
{

  Word PC;
  Word SP;
  
  Byte A;
  Byte X;
  Byte Y;
  
  Byte C : 1;
  Byte Z : 1;
  Byte I : 1;
  Byte D : 1;
  Byte B : 1;
  Byte V : 1;
  Byte N : 1;
  
  void Reset(Mem &mem);
  void Execute(u32 cycles, Mem& mem);
    
};

void CPU::Reset(Mem& mem)
{
    PC = 0xFFFC;
    SP = 0x00FF;
    A = 0;
    X = 0;
    Y = 0;
    mem.Initialize();
}

void CPU::Execute(u32 cycles, Mem& mem)
{
    std::cout << "DOES NOTHING :(" << std::endl;
}

int main()
{
    CPU cpu;
    Mem mem;
    cpu.Reset(mem);
    cpu.Execute(1, mem);
    return 0;
}
