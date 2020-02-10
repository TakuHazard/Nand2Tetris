#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

string remove_spaces(string s);
string push_segment(string s);
string pop_segment(string s);
string push_arg(string s);
string pop_arg(string s);

bool is_push(string instruction);
bool is_pop(string instruction);
bool is_eq(string instruction);
bool is_lt(string instruction);
bool is_gt(string instruction);
bool is_add(string instruction);
bool is_sub(string instruction);
bool is_neg(string instruction);
bool is_and(string instruction);
bool is_or(string instruction);
bool is_not(string instruction);

void push_writer(string instruction, fstream &output_stream,int count, string filename_no_ext);
void pop_writer(string instruction, fstream &output_stream,int count, string filename_no_ext);
void add_writer(string instruction, fstream &output_stream,int count);
void sub_writer(string instruction, fstream &output_stream,int count);
void eq_writer(string instruction, fstream &output_stream,int count);
void lt_writer(string instruction, fstream &output_stream,int count);
void gt_writer(string instruction, fstream &output_stream,int count);
void neg_writer(string instruction, fstream &output_stream,int count);
void and_writer(string instruction, fstream &output_stream,int count);
void or_writer(string instruction, fstream &output_stream,int count);
void not_writer(string instruction, fstream &output_stream,int count);




int main(int argc, char* argv[])
{
    //Trying to parse the given instruction into it's components
    


    fstream input_stream;
    int count = 0;
    fstream output_stream;
    cout<<"Enter file name without the .vm extension"<<endl;
    string filename_no_ext;
    string filename;
    getline(cin,filename_no_ext);
    filename = filename_no_ext + ".vm";
    input_stream.open(filename,ios::in);

    string output_file = filename_no_ext + ".asm";
    output_stream.open(output_file,ios::out);
    while(!input_stream.eof())
    {
        string instruction;
        getline(input_stream,instruction);
        if(instruction[0]=='/')
        {
            continue;
        }
        else if(instruction.empty())
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
        else
        {
            instruction = remove_spaces(instruction);
            int length = instruction.size();
            instruction = remove_spaces(instruction);

            bool pop = is_pop(instruction);
            bool push = is_push(instruction);
            bool eq = is_eq(instruction);
            bool lt = is_lt(instruction);
            bool gt = is_gt(instruction);
            bool add = is_add(instruction);
            bool sub = is_sub(instruction);
            bool neg = is_neg(instruction);
            bool and_state = is_and(instruction);
            bool or_state = is_or(instruction);
            bool not_state = is_not(instruction);
            output_stream<<"//instruction: " <<instruction<<endl;

            if(push)
            {
                push_writer(instruction,output_stream,count,filename_no_ext);
            }
            else if(pop)
            {
                pop_writer(instruction, output_stream,count,filename_no_ext);
            }

            else if(eq)
            {
                eq_writer(instruction, output_stream,count);
            }

            else if(lt)
            {
                lt_writer(instruction, output_stream,count);
            }

            else if(gt)
            {
                gt_writer(instruction, output_stream,count);
            }

            else if(add)
            {
                add_writer(instruction,output_stream,count);
            }

            else if(sub)
            {
                sub_writer(instruction,output_stream,count);
            }

            else if(neg)
            {
                neg_writer(instruction, output_stream,count);
            }
            else if(and_state)
            {
                and_writer(instruction, output_stream,count);
            }
            else if(or_state)
            {
                or_writer(instruction, output_stream,count);
            }
            else if(not_state)
            {
                not_writer(instruction,output_stream,count);
            }
            else
            {
                cout << " Statement not found "<<endl;
            }
            count++;
        }

}
}

void not_writer(string instruction, fstream &output_stream,int count)
{
    string count2 = to_string(count);
    cout<<"// This is an not statement"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"M = M - 1"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M " <<endl;
    output_stream<<"D = M " <<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = D " <<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"D = M"<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = !D"<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"D = M"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"M = D"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"M = M + 1"<<endl;

}


void or_writer(string instruction, fstream &output_stream,int count)
{
     string count2 = to_string(count);
    cout<<"// This is an or statement"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"M = M - 1 "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = D "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"M = M - 1"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@R14"<<endl;
    output_stream<<"M = D"<<endl;
    output_stream<<"@R14"<<endl;
    output_stream<<"D = M"<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = D|M"<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"D = M"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"M = D "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"M = M + 1"<<endl;

}

void and_writer(string instruction, fstream &output_stream,int count)
{
    string count2 = to_string(count);
    cout<<"// This is an and statement "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"M = M - 1 "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = D "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"M = M - 1"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@R14"<<endl;
    output_stream<<"M = D"<<endl;
    output_stream<<"@R14"<<endl;
    output_stream<<"D = M"<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = D & M"<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"D = M"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"M = D "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"M = M + 1"<<endl;


}

void neg_writer(string instruction, fstream &output_stream,int count)
{
    cout<<"// This is a neg statement "<<endl;

    string count2 = to_string(count);
    output_stream<<"@SP"<<endl;
    output_stream<<"M = M - 1"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = D "<<endl;
    output_stream<<"@R14"<<endl;
    output_stream<<"M = D "<<endl;
    output_stream<<"@R14"<<endl;
    output_stream<<"D =  M"<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = M - D "<<endl;
    output_stream<<"@R14"<<endl;
    output_stream<<"D =  M "<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = M - D"<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"D = M"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"M = D "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"M = M + 1 "<<endl;

}

void gt_writer(string instruction, fstream &output_stream,int count)
{
    cout<<" // This is a gt statement"<<endl;
    string count2 = to_string(count);
    output_stream<<"@SP"<<endl;
    output_stream<<"M = M - 1"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = D "<<endl;

    output_stream<<"@SP"<<endl;
    output_stream<<" M = M - 1 "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M"<<endl;
    output_stream<<"D = M"<<endl;
    output_stream<<"@R14"<<endl;
    output_stream<<"M = D "<<endl;

    output_stream<<"@R14"<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = D - M "<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"D = M "<<endl;

// Now I we have to check and see if the digit1 is greater than 0
    output_stream<<"@True"+count2<<endl;
    output_stream<<"D;JGT"<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = 0"<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"M = D "<<endl;

    // output_stream<<"@SP"<<endl;
    // output_stream<<" M = M + 1"<<endl;

    output_stream<<"@END"+count2 <<endl;
    output_stream<<"0;JMP"<<endl;

    output_stream<<"(True"+count2 + ")"<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = -1"<<endl;
    output_stream<<"D = M"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"M = D "<<endl;

    output_stream<<"@END"+count2  <<endl;
    output_stream<<"0;JMP"<<endl;

    output_stream<<"(END" + count2 + ")"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<" M = M + 1"<<endl;
}

void lt_writer(string instruction, fstream &output_stream,int count)
{
    string count2 = to_string(count);
    cout<<" // This is a lt statement"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"M = M - 1"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = D "<<endl;

    output_stream<<"@SP"<<endl;
    output_stream<<" M = M - 1 "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M"<<endl;
    output_stream<<"D = M"<<endl;
    output_stream<<"@R14"<<endl;
    output_stream<<"M = D "<<endl;

    output_stream<<"@R14"<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = D - M "<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"D = M "<<endl;

// Now I we have to check and see if the digit1 is greater than 0
    output_stream<<"@True"+count2<<endl;
    output_stream<<"D;JLT"<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = 0"<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"M = D "<<endl;

    output_stream<<"@END"+count2<<endl;
    output_stream<<"0;JMP"<<endl;

    //output_stream<<"@SP"<<endl;
    //output_stream<<" M = M + 1"<<endl;

    output_stream<<"(True" +count2+")"<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = -1"<<endl;
    output_stream<<"D = M"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"M = D "<<endl;

    output_stream<<"@END"+count2  <<endl;
    output_stream<<"0;JMP"<<endl;

    output_stream<<"(END" + count2 + ")"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<" M = M + 1"<<endl;
}


void eq_writer(string instruction, fstream &output_stream,int count)
{
    string count2 = to_string(count);
    cout<<" // This is a eq statement"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"M = M - 1"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = D "<<endl;

    output_stream<<"@SP"<<endl;
    output_stream<<" M = M - 1 "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M"<<endl;
    output_stream<<"D = M"<<endl;
    output_stream<<"@R14"<<endl;
    output_stream<<"M = D "<<endl;

    output_stream<<"@R14"<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = D - M "<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"D = M "<<endl;

// Now I we have to check and see if the digit1 is greater than 0
    output_stream<<"@True"+count2<<endl;
    output_stream<<"D;JEQ"<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = 0"<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"M = D "<<endl;

    output_stream<<"@END"+count2<<endl;
    output_stream<<"0;JMP"<<endl;

  //  output_stream<<"@SP"<<endl;
  //  output_stream<<" M = M + 1"<<endl;

    output_stream<<"(True" +count2+")"<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = -1"<<endl;
    output_stream<<"D = M"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"M = D "<<endl;

     output_stream<<"@END"+count2<<endl;
    output_stream<<"0;JMP"<<endl;

     output_stream<<"(END" + count2 + ")"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<" M = M + 1"<<endl;


}

void sub_writer(string instruction, fstream &output_stream,int count)
{
    string count2 = to_string(count);
    cout<<" // This is a substraction statement"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"M = M - 1"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = D "<<endl;

    output_stream<<"@SP"<<endl;
    output_stream<<" M = M - 1 "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M"<<endl;
    output_stream<<"D = M"<<endl;
    output_stream<<"@R14"<<endl;
    output_stream<<"M = D "<<endl;

    output_stream<<"@R14"<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = D - M "<<endl;

    output_stream<<"@R13"<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"M = D "<<endl;

    output_stream<<"@SP"<<endl;
    output_stream<<" M = M + 1"<<endl;
}
void add_writer(string instruction, fstream &output_stream,int count)
{
    string count2 = to_string(count);
    cout<<" //This is an add statement "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"M = M - 1"<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"D = M "<<endl;
    
    
    output_stream<<"@R13"<<endl;
    output_stream<<"M = D "<<endl;

    output_stream<<"@SP"<<endl;
    output_stream<<" M = M - 1 "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M"<<endl;
    output_stream<<"D = M"<<endl;
    output_stream<<"@R14"<<endl;
    output_stream<<"M = D "<<endl;

    output_stream<<"@R14"<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@R13"<<endl;
    output_stream<<"M = D + M "<<endl;

    output_stream<<"@R13"<<endl;
    output_stream<<"D = M "<<endl;
    output_stream<<"@SP"<<endl;
    output_stream<<"A = M "<<endl;
    output_stream<<"M = D "<<endl;

    output_stream<<"@SP"<<endl;
    output_stream<<" M = M + 1"<<endl;

}

void pop_writer(string instruction, fstream &output_stream,int count, string filename_no_ext)
{
    string count2 = to_string(count);
    cout<<"// This is a pop statement "<<endl;
    string segment = pop_segment(instruction);
    string arg = pop_arg(instruction);

    if(segment == "local")
    {
        segment = "LCL";
    }
    else if(segment == "argument")
    {
        segment = "ARG";
    }
    else if(segment == "this")
    {
        segment = "THIS";
    }
    else if(segment == "that")
    {
        segment = "THAT";
    }
    else if(segment == "temp")
    {
        stringstream geek(arg);
        int x = 0;
        geek >> x;
        x = 5 + x;
        string new_arg = to_string(x);
        segment = new_arg;
       
        output_stream<<"@SP"<<endl;
        output_stream<<"M = M - 1"<<endl;

        output_stream<<"@SP"<<endl;
        output_stream<<"A = M"<<endl;
        output_stream<<"D = M "<<endl;

        output_stream<<"@"+segment<<endl;
        output_stream<<"M = D"<<endl;
        return;
    }
    else if(segment == "pointer")
    {
        if(arg == "0")
        {
            output_stream<<"@SP"<<endl;
            output_stream<<"M = M - 1"<<endl;
            output_stream<<"@SP"<<endl;
            output_stream<<"A = M "<<endl;
            output_stream<<"D = M "<<endl;
            output_stream<<"@THIS"<<endl;
            output_stream<<"M = D " <<endl;
            return;
        }
        else
        {
            output_stream<<"@SP"<<endl;
            output_stream<<"M = M - 1"<<endl;
            output_stream<<"@SP"<<endl;
            output_stream<<"A = M "<<endl;
            output_stream<<"D = M "<<endl;
            output_stream<<"@THAT"<<endl;
            output_stream<<"M = D " <<endl;
            return;
        }
    }
    else if(segment == "static")
    {
        cout<< " ENTERED STATIC POP "<<endl;
        segment = filename_no_ext +"."+arg;
        cout<<"SEGMENT FOR STATIC "<<segment<<endl;
        output_stream<<"@SP"<<endl;
        output_stream<<"M = M - 1"<<endl;

        output_stream<<"@SP"<<endl;
        output_stream<<"A = M"<<endl;
        output_stream<<"D = M "<<endl;

        output_stream<<"@"+segment<<endl;
        output_stream<<" M = D "<<endl;

    return;

    }

    else
    {
        ;
    }

    output_stream<<"@"+arg<<endl;
    output_stream<<"D = A"<<endl;

    output_stream<<"@"+segment<<endl;
    output_stream<<"D = D + M"<<endl;

   // output_stream<<"@addr"+count2<<endl;


    //POTENTIALLY USE R13 INSTEAD AS THESE ARE GENERAL REGISTERS
    output_stream<<"@R13"<<endl;
    output_stream<<"M = D"<<endl;
    // output_stream<<"M = D"<<endl;

    output_stream<<"@SP"<<endl;
    output_stream<<"M = M - 1"<<endl;

    output_stream<<"@SP"<<endl;
    output_stream<<"A = M"<<endl;
    output_stream<<"D = M "<<endl;


    output_stream<<"@R13"<<endl;
    output_stream<<"A = M"<<endl;
    output_stream<<"M = D "<<endl;

    return;
}

void push_writer(string instruction, fstream &output_stream,int count, string filename_no_ext)
{
        string count2 = to_string(count);
        cout<<" // This is a push statment"<<endl;
        string segment = push_segment(instruction);
        //cout<<" This is the push segment "<<segment<<endl;
        string arg = push_arg(instruction);
        //cout<<" Arg : "<<arg<<endl;
        //cout<<" With size "<<arg.size()<<endl;

    if(segment == "local")
    {
        segment = "LCL";
    }
    else if(segment == "argument")
    {
        segment = "ARG";
    }
    else if(segment == "this")
    {
        segment = "THIS";
    }
    else if(segment == "that")
    {
        segment = "THAT";
    }
    else if(segment == "temp")
    {
        stringstream geek(arg);
        int x = 0;
        geek >> x;
        x = 5 + x;
        string new_arg = to_string(x);
        segment = new_arg;
        cout<<" TEMP SEGMENT "<<segment<<" with size " <<segment.size()<<endl;
        output_stream<<"@"+segment<<endl;
        output_stream<<"D = M "<<endl;
        output_stream<<"@SP"<<endl;
        output_stream<<"A = M "<<endl;
        output_stream<<"M = D"<<endl;
        output_stream<<"@SP"<<endl;
        output_stream<<"M = M + 1"<<endl;
        return;
    }
    else if(segment == "pointer")
    {
        // check to see if the arg is 0. If it is then push this*
        // else push that*
        if(arg == "0")
        {
            output_stream<<"@THIS"<<endl;
            output_stream<<"D = M"<<endl;
            output_stream<<"@SP"<<endl;
            output_stream<<"A = M"<<endl;
            output_stream<<"M = D "<<endl;
            output_stream<<"@SP"<<endl;
            output_stream<<"M = M + 1"<<endl;
            return;
        }
        else
        {
            output_stream<<"@THAT"<<endl;
            output_stream<<"D = M"<<endl;
            output_stream<<"@SP"<<endl;
            output_stream<<"A = M"<<endl;
            output_stream<<"M = D "<<endl;
            output_stream<<"@SP"<<endl;
            output_stream<<"M = M + 1"<<endl;
            return;
        }
    }
    else if(segment == "static")
    {
        segment = filename_no_ext + "."+arg;
        output_stream<<"@"+segment<<endl;
        output_stream<<"D = M "<<endl;
        output_stream<<"@SP"<<endl;
        output_stream<<"A = M "<<endl;
        output_stream<<"M = D"<<endl;
        output_stream<<"@SP"<<endl;
        output_stream<<"M = M + 1"<<endl;
        return;

    }
    else
    {
        ;
    }

    if(segment == "constant")
    {
        output_stream<<"@"+arg<<endl;
        output_stream<<"D = A "<<endl;
        output_stream<<"@SP"<<endl;
        output_stream<<"A = M "<<endl;
        output_stream<<"M = D"<<endl;
        output_stream<<"@SP"<<endl;
        output_stream<<"M = M + 1"<<endl;
    }
    else
    {
        output_stream<<"@"+segment<<endl;
        output_stream<<"D = M "<<endl;
        output_stream<<"@"+arg<<endl;
        output_stream<<"D = D + A"<<endl;
        output_stream<<"A = D "<<endl;
        output_stream<<"D = M "<<endl;
        output_stream<<"@SP"<<endl;
        output_stream<<"A = M "<<endl;
        output_stream<<"M = D"<<endl;
        output_stream<<"@SP"<<endl;
        output_stream<<"M = M + 1"<<endl;
    }

return;
}

bool is_not(string instruction)
{
    int length = instruction.size();
    string word = "";
    bool present = false;
    for(int i = 0; i < length; i++)
    {
        char element = instruction[i];
        word = word + element;
        if(word == "not")
        {
            present = true;
            break;
        }
    }
    return present;
}

bool is_or(string instruction)
{
    int length = instruction.size();
    string word = "";
    bool present = false;
    for(int i = 0; i < length; i++)
    {
        char element = instruction[i];
        word = word + element;
        if(word == "or")
        {
            present = true;
            break;
        }
    }
    return present;
}

bool is_and(string instruction)
{
    int length = instruction.size();
    string word = "";
    bool present = false;
    for(int i = 0; i < length; i++)
    {
        char element = instruction[i];
        word = word + element;
        if(word == "and")
        {
            present = true;
            break;
        }
    }
    return present;
}

bool is_neg(string instruction)
{
    int length = instruction.size();
    string word = "";
    bool present = false;
    for(int i = 0; i < length; i++)
    {
        char element = instruction[i];
        word = word + element;
        if(word == "neg")
        {
            present = true;
            break;
        }
    }
    return present;
}

bool is_sub(string instruction)
{
    int length = instruction.size();
    string word = "";
    bool present = false;
    for(int i = 0; i < length; i++)
    {
        char element = instruction[i];
        word = word + element;
        if(word == "sub")
        {
            present = true;
            break;
        }
    }
    return present;
}

bool is_add(string instruction)
{
    int length = instruction.size();
    string word = "";
    bool present = false;
    for(int i = 0; i < length; i++)
    {
        char element = instruction[i];
        word = word + element;
        if(word == "add")
        {
            present = true;
            break;
        }
    }
    return present;
}

bool is_gt(string instruction)
{
    int length = instruction.size();
    string word = "";
    bool present = false;
    for(int i = 0; i < length; i++)
    {
        char element = instruction[i];
        word = word + element;
        if(word == "gt")
        {
            present = true;
            break;
        }
    }
    return present;
}

bool is_lt(string instruction)
{
    int length = instruction.size();
    string word = "";
    bool present = false;
    for(int i = 0; i < length; i++)
    {
        char element = instruction[i];
        word = word + element;
        if(word == "lt")
        {
            present = true;
            break;
        }
    }
    return present;
}

bool is_eq(string instruction)
{
    int length = instruction.size();
    string word = "";
    bool present = false;
    for(int i = 0; i < length; i++)
    {
        char element = instruction[i];
        word = word + element;
        if(word == "eq")
        {
            present = true;
            break;
        }
    }
    return present;
}

string pop_arg(string s)
{
    int length = s.size();
    string arg = "";
    int count = 3;
    while(count<length)
    {
        char element = s[count];
        if(element!='0'&& element!='1' && element!='2' && element!='3' && element!='4' && element!='5' && element!='6' && element!='7' && element!='8' && element!='9')
        {
            count++;
            continue;
        }
        else
        {
            arg += element;
            count++;
        }
    }

    return arg;
}

string push_arg(string s)
{
    int length = s.size();
    string arg = "";
    int count = 4;
    while(count<length)
    {
        char element = s[count];
        if(element!='0'&& element!='1' && element!='2' && element!='3' && element!='4' && element!='5' && element!='6' && element!='7' && element!='8' && element!='9')
        {
            count++;
            continue;
        }
        else
        {
            arg += element;
            count++;
        }
    }

    return arg;
}

string pop_segment(string s)
{
    int length = s.size();
    int count = 3;
    string segment = "";
    while(count < length && s[count] != '0'  && s[count]!= '1' && s[count]!='2' && s[count]!='3' && s[count]!='4' && s[count]!='5' && s[count]!='6' && s[count] != '7' && s[count]!= '8' && s[count]!= '9')
    {
        char element = s[count];
        segment = segment + element;
        count++ ;
    }
return segment;
}


string push_segment(string s)
{
    int length = s.size();
    int count = 4;
    string segment = "";
    while(count < length && s[count] != '0'  && s[count]!= '1' && s[count]!='2' && s[count]!='3' && s[count]!='4' && s[count]!='5' && s[count]!='6' && s[count] != '7' && s[count]!= '8' && s[count]!= '9')
    {
        char element = s[count];
        segment = segment + element;
        count++ ;
    }
return segment;
}


bool is_pop(string instruction)
{
    bool pop = false;
    string traversal ="";
    int count = 0;
    while((traversal!="push"&&traversal!="pop") &&count<instruction.size())
    {
        char element = instruction[count];
        traversal += element;
        count++;
    }

    if(traversal=="pop")
    {
        pop = true;
        cout<<" This is a pop statement"<<endl;
    }
    else
    {
        pop = false;
    }

    return pop;

}


bool is_push(string instruction)
{
    bool push = false;
    string traversal ="";
    int count = 0;
    while((traversal!="push"&&traversal!="pop") &&count<instruction.size())
    {
        char element = instruction[count];
        traversal += element;
        count++;
    }

    if(traversal=="push")
    {
        push = true;
       // cout<<" This is a push statement"<<endl;
    }
    else
    {
        push = false;
    }

    return push;

}

string remove_spaces(string s)
{
    string new_string;
    int length = s.size();
    for(int i = 0; i < length; i++)
    {
        char element = s[i];
        if(s[i]==' ')
        {
            continue;
        }
        else
        {
            new_string += element;
        }

    }
   return new_string;
}
