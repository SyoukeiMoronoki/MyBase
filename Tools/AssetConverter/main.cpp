#include <stdio.h>
#include <crtdbg.h> 
#include <cstddef>

#include "Director.h"

int main()
{
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

  AssetConverterDirector* director = &AssetConverterDirector::GetInstance();

  director->Init();

  director->Import();
  director->Export();
  director->CreateProgram();

  director->Uninit();

  std::cout << "\n�I������ɂ͉����L�[�������Ă��������B" << std::endl;
  getchar();

  return 0;
}

void NativeProcess::Graphics::PackColor4u8(T_FIXED_UINT32* color, T_UINT8 r, T_UINT8 g, T_UINT8 b, T_UINT8 a)
{
}