#include <iostream>

using namespace std;
// to take in standard input and output from the terminal

// create data array with each byte assigned 0.
unsigned char memory[30000] = {0};
// ptr here is the data pointer which traverses the memory data array
unsigned char* ptr = memory;

void interpret(string str);

int main()
{
    string input;
    string program;

    // cin.get(input, sizeof(input));
    /* cin.get() may not handle newlines correctly, and may cause issues
        with brainfuck programs that have spaces/newlines between them
    */

    while(getline(cin, input) && !input.empty())
    {
        program += input;
    }

    interpret(program);
    putchar('\n');

    return 0;
}

void interpret(string str)
{
    string output;
    char curr_char;
    unsigned int i, loop;

    for(i = 0; i < str.length(); ++i)
    {
        curr_char = str[i];

        switch(curr_char)
        {
            case '>':
                ++ptr;
                break;
            
            case '<':
                --ptr;
                break;
            
            case '+':
                ++*ptr;
                break;
            
            case '-':
                --*ptr;
                break;
            
            case '.':
                putchar(*ptr & 0xFF); 
                output += *ptr;
                // Mask to 8 bits to ensure wrapping behavior
                break;
            
            case ',':
                cout << "input: ";
                *ptr = getchar();
                break;
            
            case '[':
                if (*ptr == 0)
                {
                    loop = 1;
                    while (loop > 0)
                    {
                        curr_char = str[++i];
                        if (curr_char == '[')
                            loop++;
                        else if (curr_char == ']')
                            loop--;
                    }
                }
                break;
            
            case ']':
                if (*ptr)
				{
					loop = 1;
					while (loop > 0)
					{
						curr_char = str[--i];
						if (curr_char == '[')
							loop--;
						else if (curr_char == ']')
							loop++;
					}
				}
        }
    }

    cout << output << endl;
}
