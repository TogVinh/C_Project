// Function to convert Morse code to text
char morsecode_to_text(char input[], int index)
{

    int index_1 = 0, index_2 = 0, x = 0;
    char output[100] = {'\0'}; // Variable to keep output and later used to display text
    char string[50] = {'\0'};  // Variable to combine output

    char *characters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U",
                          "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};

    char *morsecode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
                         ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....",
                         "--...", "---..", "----.", "-----"};

    while (input[index] < 1000)
    {
        if (input[index] != '\0')
        {
            if (input[index] == '.' || input[index] == '-')
            {
                // Compare if input Morse code is similar to Morse code in array
                while (input[index] == '.' || input[index] == '-')
                {
                    string[index_1] = input[index];
                    index += 1;
                    ++index_1;
                } // end of while loop

                for (index_2 = 0; index_2 < 36; index_2++)
                {
                    if (strcmp(string, morsecode[index_2]) == 0)
                    {
                        strcat(output, characters[index_2]);
                        x = 1;
                    }
                } // end of for loop

                memset(string, 0, sizeof(string));
                // Check for spaces
            }
            else if (input[index] == ' ')
            {
                if (input[index + 1] == ' ')
                {
                    if ((input[index + 2] == ' ') && (input[index + 3] == ' '))
                    {
                        strcat(output, " ");
                        index += 4;
                    }
                    else
                    {
                        strcpy(output, "FAIL - WRONG MORSE CODE");
                        break;
                    }
                }
                else
                    index++;
            }
            else if (input[index] == '\0' || input[index] == '\n' || input[index] != '.' || input[index] != '-')
            {
                break;
            }
        }
        else
            break;
    } // end of while loop

    if (x == 1)
    {
        printf("MORSE CODE TRANSLATED : SUCCESS - %s", output);
    }
    else
    {
        strcpy(output, "FAIL - WRONG MORSE CODE");
        printf("%s", output);
    }

} // end of Function to convert Morse code to text

void main()
{
    char input[1000] = {'\0'}; // User input
    char choice = 'y';         // Amount of time user wants to replay
    int index = 0;

    do
    {
        system("cls");
        printf("MORSE CODE TRANSLATOR PROGRAM\n");
        printf("\nPlease enter a Morse code string: ");
        fgets(input, 1000, stdin);

        morsecode_to_text(input, index);

        printf("\n\nDo you want to try again? (Press 'y' for Yes and 'n' for No): ");
        scanf("%c", &choice);
        getchar();
    } while (choice == 'y'); // end of while loop
} // end of void main
