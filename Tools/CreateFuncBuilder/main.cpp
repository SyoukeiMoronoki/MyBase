#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

static const string MACRO_PATH = "Engine/Core/Macro/ObjectMacro.AutoGenerated.h";

void Create(int argnum, string* dest);

int main()
{
  string header;
  header.append("#pragma once\n");
  header.append("// auto generated by CreateFuncBuilder\n");
  header.append("\n");
  Create(10, &header);

  std::ofstream ofs(MACRO_PATH);
  ofs << header;
  ofs.close();

  std::cout << "//==================================================" << std::endl;
  std::cout << "// " << MACRO_PATH << std::endl;
  std::cout << "//==================================================" << std::endl;
  std::cout << header;

  getchar();
}

void AppendComment(const string& comment, int argnum, string* dest)
{
  dest->append("/*!\n");
  dest->append(" * @brief " + comment + "\n");
  dest->append(" * 引数" + to_string(argnum) + "個バージョン\n");
  dest->append(" */\n");
}

string CreateArgment(int argnum)
{
  string ret;
  for (int i = 0; i < argnum; ++i)
  {
    if (i > 0)
    {
      ret.append(", ");
    }
    string s = to_string(i);
    ret.append("Arg" + s);
  }
  return ret;
}

string CreateArgmentSharp(int argnum)
{
  string ret;
  for (int i = 0; i < argnum; ++i)
  {
    if (i > 0)
    {
      ret.append("\", \"");
    }
    string s = to_string(i);
    ret.append("#Arg" + s);
  }
  return ret;
}

string CreateArgmentImpl(int argnum)
{
  string ret;
  for (int i = 0; i < argnum; ++i)
  {
    if (i > 0)
    {
      ret.append(", ");
    }
    string s = to_string(i);
    ret.append("Arg" + s + " arg" + s);
  }
  return ret;
}

string CreateArgmentCall(int argnum)
{
  string ret;
  for (int i = 0; i < argnum; ++i)
  {
    if (i > 0)
    {
      ret.append(", ");
    }
    string s = to_string(i);
    ret.append("arg" + s);
  }
  return ret;
}

string CreateMacroCall(const string& name, int argnum)
{
  string ret;
  string suffix;
  string type = "Type";
  if (argnum > 0)
  {
    suffix = "_" + to_string(argnum);
    type += ", ";
  }
  ret.append(name + suffix + "(" + type + CreateArgmentImpl(argnum) + ")");
  return ret;
}

void AppendMacro(const string& name, int argnum, string* dest)
{
  string suffix;
  string type = "Type";
  if (argnum > 0)
  {
    suffix = "_" + to_string(argnum);
    type += ", ";
  }
  dest->append("#define " + name + suffix + "(" + type + CreateArgment(argnum) + ")");
}

void AppendMacroLine(string* dest, const string& line)
{
  dest->append("\\\n" + line);
}

void AppendDefineInitFunc(int argnum, string* dest)
{
  AppendComment("GGObjectの初期化関数宣言", argnum, dest);
  AppendMacro("GG_INIT_FUNC", argnum, dest);
  AppendMacroLine(dest, "protected:");
  AppendMacroLine(dest, "  virtual bool Init(" + CreateArgment(argnum) + ")");
  dest->append("\n\n");
}

void AppendDefineInitFuncImpl(int argnum, string* dest)
{
  AppendComment("GGObjectの初期化関数実装", argnum, dest);
  AppendMacro("GG_INIT_FUNC_IMPL", argnum, dest);
  AppendMacroLine(dest, "bool Type::Init(" + CreateArgment(argnum) + ")");
  dest->append("\n\n");
}

void AppendDefineCreateFunc(int argnum, string* dest)
{
  AppendComment("GGObjectのCreateMethodを定義する", argnum, dest);
  AppendMacro("GG_CREATE_FUNC", argnum, dest);
  AppendMacroLine(dest, "public:");
  AppendMacroLine(dest, "  static UniqueRef<Type> Create(" + CreateArgmentImpl(argnum) + ")");
  AppendMacroLine(dest, "  {");
  AppendMacroLine(dest, "    Type* ret = new (std::nothrow) Type();");
  AppendMacroLine(dest, "    GG_ASSERT(ret != nullptr, #Type\"::Create(\"" + CreateArgmentSharp(argnum) + "\"): インスタンスの生成に失敗しました\");");
  AppendMacroLine(dest, "    if (!ret->Init(" + CreateArgmentCall(argnum) + "))");
  AppendMacroLine(dest, "    {");
  AppendMacroLine(dest, "      GG_ASSERT(false, #Type\"::Init(\"" + CreateArgmentSharp(argnum) + "\"): インスタンスの初期化に失敗しました\");");
  AppendMacroLine(dest, "    }");
  AppendMacroLine(dest, "    return UniqueRef<Type>(ret);");
  AppendMacroLine(dest, "  }");
  AppendMacroLine(dest, CreateMacroCall("GG_INIT_FUNC", argnum));
  dest->append("\n\n");
}

void Create(int argnum, string* dest)
{
  for (int i = 0; i < argnum; ++i)
  {
    AppendDefineInitFunc(i, dest);
    AppendDefineInitFuncImpl(i, dest);
    AppendDefineCreateFunc(i, dest);
  }
}
