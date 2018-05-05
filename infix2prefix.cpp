#include <iostream>
#include <stack>
#include <fstream>
#include <vector>

std::string getLine(std::ifstream& in)
{
  std::string line = "";
  std::string word = "";
  
  while(in >> word && word != ";")
  {
    line += word + " ";
  }
  return line;
}

std::string inToPre(std::string expression)
{
  for(int i = 0; i < expression.length(); i++)
  {
    while(expression[i] != ' ')
    {
      tempstr += expression[i];
      i++;
    }
    
    if(tempstr == ")")
    {
      std::string right = stack.top();
      stack.pop();
      std::string oper = stack.top();
      stack.pop();
      std::string left = stack.top();
      stack.pop();
      std::string Result = oper + " " + left + " " + right;
      
      stack.push(Result);
    }
    else if(tempstr != "(")
    {
      stack.push(tempstr);
    }
    tempstr = "";
  }
  return stack.top():
}

int main(int argc, char* argv[])
{
  if(argc != 2 && argc != 3)
  {
    std::cout << "Invalid number of arguments." << std::endl;
    std::cout << "Expecting ./fix inputfile [output file]" << std::endl;
    return 1;
  }
  
  std::ifstream infix (arv[1]);
  if(!infix.is_open())
  {
    std::cout << "invalid input" << std::endl;
    return 2;
  }
  std::ofstream output (argv[2]);
  if(argc == 3 && !output.is_open())
  {
    std::cout << "Invalid output" << std::endl;
    return 3;
  }
  
  std::string expression = getLine(infix);
  while(!infix.eof())
  {
    std::string prefix = inToPre(expression);
    if(argc == 2)
    {
      std::cout << "Infix: " << expression << std::endl;
      std::cout << "Prefix: " << prefix << std::endl;
    }
    else
    {
      output << "Infix: " << expression << std::endl;
      output << "Prefix: " << prefix << std::endl;
    }
    expression = getLine(infix);
  }
  return 0;
}
