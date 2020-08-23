/********************************************************************************************
** Program: main.hpp
** Author: Hailey Wilder
** Date: 02/21/2017
** Description: This program implements an abstract data tye using linked structures. 
*********************************************************************************************/
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Queue.hpp"

int main()
{
    char choice;
    Queue stack; // create a stack container that will hold the integers enterned by user
    int const size = 1000; 
    char x[size];
	char integers[size];
	int value;
	bool check;
    

    std::cout << "\nWelcome to Lab 8!\n";

    while (true)
    {
		//do
		//{
			std::cout << "Menu Selection:\n";
    		std::cout << "a) Enter a value\n";
    		std::cout << "b) Display first value\n";
    		std::cout << "c) Remove a value\n";
    		std::cout << "d) Display the queue contents\n";
			std::cout << "e) Run test code\n";
    		std::cout << "x) Exit\n\n";
			std::cout << "Selection: ";
			std::cin.getline(x, size);
			std::cout << "\n";

	
			if (x[0] == 'a')
				{
					if (x[1] == ')')
						{
							if (x[2] == ' ')
								if (isdigit(x[3])) 
									{
										int counter = 0;

										for (int a = 0; a < size; a++)
											integers[a] = 'p';

										for (int y = 3; y < size; y++)
										{
											if (x[y] != 'p')
												{
													integers[counter] = x[y];
												}
											counter++;
										}	
										integers[counter] = 'p';	
										value = atoi (integers);
										
										check = true;				
									}
								else
									{ 
										std::cin >> value;
										while (value < 0 || !std::cin.good())
										{
											std::cin.clear();
											std::cin.ignore(256, '\n');
											std::cout << "Not a valid digit! Enter value again: ";
											std::cin >> value;
											check = false;
										}
									}		
							else
								{
									std::cin >> value;
									while (value < 0 || !std::cin.good())
									{
										std::cin.clear();
										std::cin.ignore(256, '\n');
										std::cout << "Not a valid digit! Enter value again: ";
										std::cin >> value;
									}
									check = true;
								}
						}
					else
						{	
							std::cout << "please add parenthese after selection... \n" << std::endl;
							check = false;
						}
				}

		//}while (check == false);
		choice = x[0];

        switch (choice)
        {
            case 'a':
            {
                std::cout << "\nAdding " << value << " (press Enter to continue if needed)...\n\n";

                stack.addBack(value);
				std::cin.clear();
				std::cin.ignore(256, '\n'); // Adding cin.ignore() to the next line clears / ignores the newline from the stream.
                break;
            }

	    case 'b':
            {
                int val = stack.getFront();
				if (val == -1) 
                    std::cout << "Empty queue!\n\n";
				else
					std::cout << "Frist value in the stack: " << val << "\n\n";
                break;
            }

            case 'c':
            {
                int val = stack.removeFront();
                if (val == -1) 
                    std::cout << "Empty queue!\n\n";
                else
                    std::cout << "Removed " << val << " from queue.\n\n";
                break;
            }
       
            case 'd':
            {
                stack.displayStackContents();
                break;
            }

			case 'e':
			{

				std::cout << "Adding 25 to the queue...\n";
				stack.addBack(25);
				std::cout << "Adding 13 to the queue...\n";
				stack.addBack(13);
				std::cout << "Adding 103 to the queue...\n";
				stack.addBack(103);
				std::cout << "Press enter to continue...\n";
				std::cin.get();
				std::cout << "Now showing first number in the queue: " << stack.getFront() << std::endl;
				stack.getFront();
				std::cout << "Press enter to continue...\n";
				std::cin.get();
				std::cout << "Now displaying queue contents: ";
				stack.displayStackContents();
				std::cout << "Press enter to continue...\n";
				std::cin.get();
				std::cout << "Now removing the numbers from the queue...\n";
				int val = stack.removeFront();
                if (val == -1) 
                    std::cout << "Empty queue!\n\n";
                else
                    std::cout << "Removed " << val << " from queue.\n\n";
				val = stack.removeFront();
                if (val == -1) 
                    std::cout << "Empty queue!\n\n";
                else
                    std::cout << "Removed " << val << " from queue.\n\n";
				val = stack.removeFront();
                if (val == -1) 
                    std::cout << "Empty queue!\n\n";
                else
                    std::cout << "Removed " << val << " from queue.\n\n";
				val = stack.removeFront();
                if (val == -1) 
                    std::cout << "Empty queue!\n\n";
                else
                    std::cout << "Removed " << val << " from queue.\n\n";
				std::cout << "Press enter to continue...\n";
				std::cin.get();
				std::cout << "Now closing program! Good bye!\n";
				std::cin.get();
				return 0;
			}
            case 'x':
            {
                return 0;
            }
        }

    }
}

