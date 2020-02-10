// This program translates from Assembly Language into binary language according to the Hack machine Language specification. There is a bug affecting the Rect file but it works for all other files. The bug has to do with indexing that for some absurd reason seems to be unique to the Rect.asm file. I am suspecting that it might have been written in a different text editor by the authors although I don't know why it would be any different.

// Append : It seems like line 428 causes bugs. I am not entirely sure what is going on.

// Fixed. Bug only appears on Repl.it. Note to self : never use Repl.it again.
#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
#include <map>
#include <fstream>
#include <iterator>
using namespace std;

string dest_finder(string c_ins);
string comp_finder(string c_ins);
string jump_finder(string c_ins);

string dest_translator(string dest);
string comp_translator(string comp);
string jump_translator(string jump);

void c_instruction_parser(string c_ins,string &comp, string &dest,string &jump);

string c_trans(string comp, string dest, string jump);

string remove_spaces(string  c_ins);
string a_instruction(string a_ins);

string instruction_writer(string instruction);

void first_parsal(fstream &input_stream, map<string,string> & variable_table);
void second_parsal(fstream &input_stream, map<string,string>& variable_table);

int main()
{
  cout<<" Enter name of input file "<<endl;
  string input_file;
  fstream input_stream;
  getline(cin,input_file);
  input_stream.open(input_file,ios::in);

  cout<<" Enter name of output file "<<endl;
  string output_file;
  fstream output_stream;
  getline(cin,output_file);
  output_stream.open(output_file,ios::out);

map <string,string> variable_table; 

variable_table.insert(pair<string,string>(remove_spaces("R0"),"0"));
variable_table.insert(pair<string,string>("SP","0"));
variable_table.insert(pair<string,string>("R1","1"));
variable_table.insert(pair<string,string>("LCL","1"));
variable_table.insert(pair<string,string>("R2","2"));
variable_table.insert(pair<string,string>("ARG","2"));
variable_table.insert(pair<string,string>("R3","3"));
variable_table.insert(pair<string,string>("THIS","3"));
variable_table.insert(pair<string,string>("R4","4"));
variable_table.insert(pair<string,string>("THAT","4"));
variable_table.insert(pair<string,string>("R5","5"));
variable_table.insert(pair<string,string>("R6","6"));
variable_table.insert(pair<string,string>("R7","7"));
variable_table.insert(pair<string,string>("R8","8"));
variable_table.insert(pair<string,string>("R9","9"));
variable_table.insert(pair<string,string>("R10","10"));
variable_table.insert(pair<string,string>("R11","11"));
variable_table.insert(pair<string,string>("R12","12"));
variable_table.insert(pair<string,string>("R13","13"));
variable_table.insert(pair<string,string>("R14","14"));
variable_table.insert(pair<string,string>("R15","15"));
variable_table.insert(pair<string,string>("SCREEN","16384"));
variable_table.insert(pair<string,string>("KBD","24576"));
first_parsal(input_stream,variable_table);
input_stream.clear();
input_stream.close();
input_stream.open(input_file,ios::in);
second_parsal(input_stream,variable_table);
input_stream.clear();
input_stream.close();
input_stream.open(input_file,ios::in);
// Last parsal
while(!input_stream.eof())
{
  cout<< " entered last loop "<<endl;
  // read the instruction
  string instruction;
  getline(input_stream,instruction);
  instruction = remove_spaces(instruction);
  //cout<<"Instruction is "<<instruction<<endl;
  //instruction = remove_spaces(instruction);
  string new_inst = "";
  // remove spaces from instruction

  // ignore instruction is empty space, comment or label declaration;
  if(instruction.empty())
  {
    cout<<" Instruction is empty "<<endl;
    continue;
  }
  else if(instruction[0]=='/')
  {
    cout<<" Instruction is a comment "<<endl;
    continue;
  }
  else if(instruction[0]=='(')
  {
    cout<<"Instruction is a label "<<endl;
    continue;
  }
  else if(instruction.size()==1)
  {
    cout<<" Instruction has size 1 for some reason "<<endl;
    continue;
  }

  // check to see if instruction is a none-numeric a_ins
  else if(instruction[0]=='@' && (instruction[1]!='1' && 
  instruction[1] != '2'&&instruction[1]!='3' &&instruction[1]!='4' && instruction[1]!='5' && instruction[1]!='6' && instruction[1]!='7' && instruction[1]!='7' && instruction[1]!='8' && instruction[1]!='9' &&instruction[1]!='0'))
  {
    // cout<<" instruction "<<instruction<<endl;
    // cout<<" Entered non number a_ins" <<endl;
    // find the rest of the word
    int length = instruction.size();
    string word ="";
     for(int i = 1; i < length - 1; i++)
      {
        char element = instruction[i];
        if(element == ' ')
        {
          break;
        }
        word = word + element;
      }
    //cout<< " word is "<<word<<endl;
    // now find the value of the word from the map. This is a numeric result
    string value = variable_table[word];
    //cout<<" value is "<<value<<endl;

    // now make a new instruction with value apppened with an @ at the front

    new_inst = '@' + value;

    // now translate using the a_instruction command.
  }
  // check to see if instruction is a numeric a_ins
  else if(instruction[0]=='@' && (instruction[1]=='1' || 
  instruction[1] == '2' || instruction[1] =='3' || instruction[1] =='4' || instruction[1]=='5' ||  instruction[1] =='6' ||instruction[1] =='7' || instruction[1]=='7' || instruction[1] =='8' || instruction[1] =='9' || instruction[1]!='0'))
  {
   // cout<<" instruction "<<instruction<<endl;
    //cout<<" Entered number a_inst "<<endl;
    // then this an alphanumeric instruction
    new_inst = instruction;
  }

  else
  {
    // else this is a bona-fide a-instruction;
    new_inst = instruction;
  }

  // now we translate and insert into output file
  string instruction_to_output = instruction_writer(new_inst);
  output_stream<<instruction_to_output<<endl;
}

cout<<endl<<endl<<endl;

}

void second_parsal(fstream &input_stream, map<string,string>& variable_table)
{
  // Now we go look for @ statements and check the map to see if they have been already predefined. Otherwise add to the map starting at position 16 !.
  while(!input_stream.eof())
  {
  string instruction;
  getline(input_stream,instruction);
  instruction = remove_spaces(instruction);
  if(instruction.empty())
  {
    continue;
  }
  else if(instruction[0]=='/')
  {
    continue;
  }
  else if(instruction.size()==0)
  {
    continue;
  }
  else if(instruction[0]=='(')
  {
    continue;
  }
  else if(instruction.size()==1)
  {
    continue;
  }
  // Now we check to see if the instruction is of the form @XXX. where XXX is a word and not a number.
  else if(instruction[0]=='@' && (instruction[1]!='1' && 
  instruction[1] !='2' &&instruction[1]!='3' &&instruction[1]!='4' && instruction[1]!='5' && instruction[1]!='6' && instruction[1]!='7' && instruction[1]!='8' && instruction[1]!='9' &&instruction[1]!='0'))
  {
    // we have 2 cases to cover.  First the rest of the string contains a variavle that has already been handled. Second the variable is a new one and needs to be added to the map.
    int length = instruction.size();
    string word ="";
    // We already know first character is @. Skip over that. Make sure you don't take a space with you.
    for(int i = 1; i < length - 1; i++)
      {
        char element = instruction[i];
        if(element == ' ')
        {
          break;
        }
        word = word + element;
      }
  //word = remove_spaces(word);
  cout << " This is the word being looked for " << word<<endl ;
  cout<<" It has size "<<word.size()<<endl;
  //cout<< "with size " << word.size()<<endl;

  // Now check to see if this key already exists in the variable_table;
  //map<string,string>::iterator it;
  if(variable_table.find(word)==variable_table.end())
  {
    // this means that the key doesn't exist.Now we try to allocate this key to a UNIQUE value. 
    int shift = 16;
    int counter = 0;
    bool unique = false;
      
    while(!unique)
    {
      for(auto it = variable_table.begin();it!= variable_table.end(); it++)
     {
      string value_under_inv = it -> second;
      if(value_under_inv == to_string(shift))
      {
          unique = false;
          shift++;
          continue;
      }
      else
      {
        unique = true;
      }
      }
    }

  // This means the current value held in shift is unique and now we can do the allocation
      variable_table.insert(pair<string,string>(word,to_string(shift)));

   } 
 else   
  { 
    
  
    // this means that the key does exist and we can continue;
    continue;
  }  

  }
  
  else
  {
    // This is either a legit @num_value or it's c_instruction and we can continue parsing through the file
    continue;
  }
}
return;


}


void first_parsal(fstream &input_stream, map<string,string> & variable_table)
{
  // traverse through the file. Ignore comments and all blank lines
  int counter = 0;
  int counter_label = 0;
  while(!input_stream.eof())
  {
    string instruction;
    getline(input_stream,instruction);
   // cout<<instruction<<endl;

    if(instruction.empty())
    {
      continue;
    }
    else if(instruction.size()==0)
    {
      continue;
    }
    else if(instruction.size()==1)
    {
      continue;
    }
    else if(instruction[0]=='/')
    {
      continue;
    }
    else if(instruction[0]=='(')
    {
      // since word is braceted we need to ignore first and last characters of the string
      counter_label++;
      int length = instruction.size();
      string word = "";
      for(int i = 1; i < length - 1; i++)
      {
        char element = instruction[i];
        if(element == ')')
        {
          break;
        }
        word = word + element;
      }
      word = remove_spaces(word);
      variable_table.insert(pair<string,string>(word,to_string(counter+1-counter_label)));
     cout<<" This the word being added : "<<word;
     cout<<" size : "<<word.size()<<endl;
     cout<<" at position "<<variable_table[word]<<endl;
      counter++;
      continue;
    }
    else
    {
      counter++;
      continue;
    }
  }
  cout<< " END OF FIRST PARSAL "<<endl;
 return;

}


string instruction_writer(string instruction)
{
  int length = instruction.size();
  instruction = remove_spaces(instruction);

  if(instruction[0]!='@')
  {
    string dest;
    string comp;
    string jump;
    c_instruction_parser(instruction,comp,dest,jump);
    cout<<" Dest : "<<dest<<endl;
    cout<<" Comp: "<<comp<<endl;
   cout<< " Comp has size "<<comp.size()<<endl;
    cout<<" Jump: "<<jump<<endl;
    string c_bool = c_trans(comp,dest,jump);
   // cout<<" C_instr in bool : "<<c_bool<<endl;
    return c_bool;
    
  }
  else
  {
    string a_inst = a_instruction(instruction);
    return a_inst;
    cout<<" A instruction is "<<a_inst<<endl;
  }
  
}

string dest_finder(string c_ins)
{
  // This assumes the statement is not empty space and is valid ( that is well written)
  string dest = "";
  int position_equals;
  int length = c_ins.size();
  bool presence = false;

  // use a for loop to find the = sign. If no equal sign then destination field is empty
  for(int i = 0; i < length ; i++)
  {
    char element = c_ins[i];
    if(element == '=')
    {
      presence = true;
      position_equals = i;
      break;
    } 
  }

  if(presence==false)
  {
    cout<< " Dest is empty "<<endl;
    return dest;
  }
  else
  {
    // else the destination is composed of elements before the equal sign.
    int counter = 0;
    while(counter < position_equals && c_ins[counter]!='=')
    {
      dest += c_ins[counter];
      counter++;
    }
    //cout<<" Out of while loop "<<endl;
    return dest;
  }
}

string comp_finder(string c_ins)
{
  string comp ="";
  int counter;
  int equal_position;
  int length = c_ins.size();

  // This function is two fold. It first traverses looking for the first equal sign. If there is an equal sign then comp field is everything after the equal upto (maynot be present) first ; not including comments. Otherwise the equal sign is everything before the ;

  bool equal_presence = false;
  for(int i = 0; i < length; i++)
  {
    char element = c_ins[i];
    if(element == '=')
    {
      equal_presence = true;
      equal_position = i;
      break;
    }
  }

  if(equal_presence == true)
  {
    // equal sign is present. Then use while loop while c_ins[counter] != // or c_ins[counter] != ; or counter == length
    counter = equal_position + 1;

    // The following line causes bugs. Is it length - 1 or length ??
    while(counter < length - 1 && c_ins[counter] != '/' && c_ins[counter]!= ';' && c_ins[counter]!=' ')
    {
      comp += c_ins[counter];
      counter++;
    }
    return comp;
  }

  else
  {
    // find the ";". Comp field is everything before the ;
    int counter_colon;
    for(int i = 0; i < length-1; i++)
    {
      char element = c_ins[i];
      if(element == ';')
      {
        counter_colon = i;
        break;
      }
    }

    for(int i = 0; i < counter_colon; i++)
    {
      char element = c_ins[i];
      if(element==' ')
      {
        break;
      }

      comp =  comp + element;
    }

    return comp;
  }
}

string jump_finder(string c_ins)
{
  string jump = "";
  bool colon_presence = false;
  int colon_location = 0;
  int length = c_ins.size();

  for(int i = 0; i < length ; i++)
  {
    char element = c_ins[i];
    if(element == ';')
    {
      colon_presence = true;
      colon_location = i;
      break;
    }
  }

  if(colon_presence == false)
  {
    return jump;
  }
  else 
  {
    int counter = colon_location + 1;

    while(counter < length -1 && c_ins[counter] != '/' && c_ins[counter]!= ';' && c_ins[counter]!=' ')
    {
      jump += c_ins[counter];
      counter++;
    }

    return jump;
  }
}

string remove_spaces(string c_ins)
{
  int length = c_ins.size();
  string new_string = "";
  int count = 0;
  for(int i = 0; i < length; i++)
  {
    char element = c_ins[i];
    if(element != ' ')
    {
      new_string += element;
      count++;
    }
  }
  return new_string;
}
void c_instruction_parser(string c_ins,string &comp, string &dest,string &jump)
{
  comp = comp_finder(c_ins);
  dest = dest_finder(c_ins);
  jump = jump_finder(c_ins);
  return;
}

string a_instruction(string a_ins)
{
  // converts an a instruction with a number at the front into it's binary equivalent;
  int length = a_ins.size();
  string number="";
  for(int i = 1; i < length; i++)
  {
    number+=a_ins[i];
  }
  stringstream geek(number);
  int x = 0;
  geek >> x;

  string binary = bitset<15>(x).to_string();
  binary = '0' + binary;

return binary;
}

string dest_translator(string dest)
{
  string binary;
  if(dest=="")
  {
    binary = "000";
  }
  else if(dest=="M")
  {
    binary = "001";
  }
  else if(dest=="D")
  {
    binary = "010";
  }
  else if(dest=="MD")
  {
    binary = "011";
  }
  else if(dest=="A")
  {
    binary = "100";
  }
  else if(dest == "AM")
  {
    binary = "101";
  }
  else if(dest == "AD")
  {
    binary = "110";
  }
  else
  {
    binary = "111";
  }

  return binary;
}

string jump_translator(string jump)
{
  string binary;
  if(jump == "")
  {
    binary = "000";
  }
  else if(jump == "JGT")
  {
    binary = "001";
  }
  else if(jump == "JEQ")
  {
    binary = "010";
  }
  else if (jump == "JGE")
  {
    binary = "011";
  }
  else if (jump == "JLT")
  {
    binary = "100";
  }
  else if (jump =="JNE")
  {
    binary = "101";
  }
  else if (jump == "JLE")
  {
    binary = "110";
  }
  else
  {
    cout<<jump<<" with size: "<<jump.size()<<endl;
    binary = "111";
  }

  return binary;
}

string comp_translator(string comp)
{
  string binary;
  if(comp=="0")
  {
    binary = "0101010";
  }
  else if(comp=="1")
  {
    binary = "0111111";
  }
  else if(comp=="-1")
  {
    binary = "0111010";
  }
  else if(comp=="D")
  {
    binary = "0001100";
  }
  else if(comp=="A")
  {
    binary = "0110000";
  }
  else if(comp=="!D")
  {
    binary = "0001101";
  }
  else if(comp=="!A")
  {
    binary = "0110001";
  }
  else if(comp == "-D")
  {
    binary = "0001111";
  }
  else if(comp == "-A")
  {
    binary = "0110011";
  }
  else if(comp =="D+1")
  {
    binary = "0011111";
  }
  else if(comp == "A+1")
  {
    binary = "0110111";
  }
  else if(comp == "D-1")
  {
    binary = "0001110";
  }
  else if(comp == "A-1")
  {
    binary = "0110010";
  }
  else if(comp == "D+A")
  {
    binary = "0000010";
  }
  else if(comp == "D-A")
  {
    binary = "0010011";
  }
  else if(comp == "A-D")
  {
    binary = "0000111";
  }
  else if(comp == "D&A")
  {
    binary = "0000000";
  }
  else if(comp == "D|A")
  {
    binary = "0010101";
  }
  else if(comp =="M")
  {
    binary = "1110000";
  }
  else if(comp =="!M")
  {
    binary = "1110001";
  }
  else if(comp == "-M")
  {
    binary = "1110011";
  }
  else if(comp =="M+1")
  {
    binary = "1110111";
  }
  else if(comp == "M-1")
  {
    binary = "1110010";
  }
  else if(comp == "D+M")
  {
    binary = "1000010";
  }
  else if(comp == "D-M")
  {
    binary = "1010011";
  }
  else if (comp == "M-D")
  {
    binary = "1000111";
  }
  else if(comp == "D&M")
  {
    binary = "1000000";
  }
  else if(comp == "D|M")
  {
    binary = "1010101";
  }
return binary;
}
string c_trans(string comp, string dest, string jump)
{
  string dest_trans = dest_translator(dest);
  cout<<" dest : "<<dest_trans<<endl;
  string comp_trans = comp_translator(comp);
  cout<<" comp : "<<comp_trans<<endl;
  string jump_trans = jump_translator(jump);
  cout<<" jump: "<<jump_trans<<endl;
  string c_bin = "111"+comp_trans+dest_trans+jump_trans;
  return c_bin;
}