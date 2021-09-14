#include <iostream>
#include <limits>

using namespace std;

int strLen(const char* s)
{
    int len=0;
    for(len; s[len] != '\0'; len++);
    return len;
}

char* cinStr()
{
    char ch;
    int siz = 300;
    char* arr = new char [siz];
    cin.ignore(1);
    for(int i=0; ch!='\n'; i++)
    {
        cin.get(ch);
        if(ch!='\n')
        {
            arr[i] = ch;
        }
        cout << '.' << ch;

        if(i == siz-1)
        {
            siz += 300;
            char* temp = arr;
            arr = new char[siz];

            for(int j=0; j<siz; j++)
            {
                arr[j] = temp[j];
            }
        }
    }
    return arr;
}
void printString(char* s)
{
    int len = strLen(s);
    for(int i=0; i<len; i++)
    {
        cout << s[i];
    }
}



class MyString
{
    char* str;
    int length;
public:
    MyString()
    {
        str = new char[1];
        str[0] = '\0';
        length = 0;
    }
    MyString(const char* s)
    {
        length = strLen(s);
        str = new char[length + 1];
        for(int i=0; i<length; i++)
        {
            str[i] = s[i];
        }
        str[length] = '\0';
    }
    MyString(const MyString& s)
    {
        length = s.length;
        str = new char[length + 1];
        for(int i=0; i<length+1; i++)
        {
            str[i] = s.str[i];
        }
    }
    ~MyString()
    {
        delete[] str;
    }

    // remove the last character from str before '\0'
    void Remove()
    {
        str [length-1] = '\0';
        length--;
        cout<<"Result: "<< str <<endl;
    }

    // add a new character item to the end of str before '\0'
    void Add(char item)
    {
        char*temp=new char[length+2];
        for(int i=0; i<length; i++)
        {
            temp[i]=str[i];
        }
        temp[length] = item;
        temp[length+1] = '\0';

        str=new char[length+2];
        for(int i=0; i<length+2; i++)
        {
            str[i]=temp[i];

        }
        length++;
        cout << str << endl;
    }

    // return the length attribute
    int Length()
    {
        return length;
    }

    // return a part of the original str
    // that part is the characters from index (pos) to index (pos+len-1) from str
    char* Copy(int pos, int len)
    {
        char* tempStr = new char[len+1];
        for(int i=pos, j=0; i<(pos+len); i++, j++)
        {
            tempStr[j] = str[i];
        }
        tempStr[len] = '\0';
        return tempStr;
    }

    // Swap str and length values by using temp method
    void Swap(MyString& s)
    {
        char* temp=new char[length+1];
        int i;
        for(int i=0; i<length+1; i++)

        {
            temp[i] =s.str[i];

        }
        temp[i] = '\0';
        for(int i=0; i<length+1; i++)
        {
            s.str[i] = str[i];

        }
        s.str[i] = '\0';

        for(int i=0; i<length+1; i++)
        {
            str[i] = temp[i];

        }
        str[i] = '\0';
        cout << "First string: ";
        for (int i = 0; i < length ; ++i)
            cout<<str[i];
        cout<<endl;
        cout << "Second string: ";
        for (int i = 0; i < length; ++i)
            cout<<s.str[i];
        cout<<endl;
    }

    // return new object with str = this.str + s.str - '\n'
    MyString operator+ (const MyString& s)
    {

        char* temp = new char[length+s.length+1];

        for(int i=0; i<length; i++)
        {
            temp[i]=str[i];
        }
        for(int i=length,j=0; i<length+s.length+1; i++,j++)
        {
            temp[i]=s.str[j];
        }

        MyString obj(temp);
        return obj;

    }

    // if(s1 < s2)--> -1, if(s1 = s2)--> 0, if(s1 > s2)--> 1
    int Compare(const MyString& s)
    {
        if(length > s.length)
        {
            return 1;
        }
        else if(length == s.length)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    // return new object with str that equal a part of this.str
    MyString SubString(int startIndex, int endIndex)
    {
        MyString obj;
        obj.str=new char [endIndex-startIndex+2];
        obj.length = endIndex-startIndex+1;
        for(int i=startIndex; i<startIndex+endIndex+1; i++)
        {
            obj.str[i-startIndex]=str[i];
        }
        return obj ;
    }

    // return new object with str equals this.str without any starting or ending spaces
    // "  Hello World!   " --> "Hello World!"
    MyString Trim()
    {
        int  space_counter=0;
        for( int i = 0; i < length; i++)
        {
            if (str[i] == ' ')
            {
                space_counter++;
            }
        }
        char*temp=new char[length-space_counter+1];
        for(int i=0,j=0; i<length; i++)
        {
            if(str[i]!=' ')
            {
                temp[j]=str[i] ;
                j++;
            }
        }
        MyString obj(temp);
        return obj;
    }

    // return new object with all capitals or opposite
    // if no changes required it return *(this)
    MyString ToLowerCase()
    {
        bool returnOriginal = true;
        MyString tempObj(*(this));
        for(int i=0; i<length; i++)
        {
            if(str[i] >= 65 && str[i] <= 90)
            {
                tempObj[i] += 32;
                if(returnOriginal) returnOriginal = false;
            }
        }
        if (returnOriginal) return *(this);
        return tempObj;
    }

    MyString ToUpperCase()
    {
        bool returnOriginal = true;
        MyString tempObj(*(this));
        for(int i=0; i<length; i++)
        {
            if(str[i] >= 97 && str[i] <= 122)
            {
                tempObj[i] -= 32;
                if(returnOriginal) returnOriginal = false;
            }
        }
        if (returnOriginal) return *(this);
        return tempObj;
    }

    // search for chr from start and return it's index
    int IndexOf(char chr)
    {
        for(int i=0; i<length; i++)
        {
            if(str[i]==chr)
            {
                return i;
            }

        }
        cout<<"Not found!\n";
        return NULL;
    }

    // search for chr from end and return it's index
    int LastIndexOf(char chr)
    {
        for(int i=length-1; i>0; i--)
        {
            if(str[i]==chr)
            {
                return i;
            }

        }
        cout<<"Not found!\n";
        return NULL;
    }

    // return a new object with the replaced characters
    MyString Replace(char oldChr, char newChr)
    {
        char* temp = new char[length];
        for (int i = 0; i < length+1; ++i)
        {
            if (str[i] == oldChr) temp[i] = newChr;
            else temp[i] = str[i];

        }

        MyString obj(temp);
        return obj;
    }

    // [] operator for using MyString[]
    char& operator[] (int index)const
    {
        return str[index];
    }

    // cout operator
    friend ostream& operator<< (ostream& output, const MyString& obj)
    {
        for(int i=0; i<obj.length; i++)
        {
            output << obj[i];
        }
        output << endl;
        return output;
    }

    // assign operator
    MyString& operator= (MyString& obj)
    {
        length = obj.length;
        delete[] str;
        str = new char[length+1];
        for(int i=0; i<length+1; i++)
        {
            str[i] = obj.str[i];
        }
        return *(this);
    }


};

int main()
{
    // loop and in-loop variables
    int choice;
    MyString str1;
    MyString str2;
    int whichString;
    char newChr;
    char oldChr;
    int pos;
    int len;
    int srtInx;
    int endInx;

    while(true)
    {
        cout << "==============================================================================" << endl;
        cout << "Enter the number to choose: " << endl;
        cout << " 0- Show the two program strings." << endl;
        cout << " 1- Enter a new string. (you can enter two different strings)" << endl;
        cout << " 2- Remove the last character form the string." << endl;
        cout << " 3- Enter and add one character to the end of string." << endl;
        cout << " 4- Print the length of the string." << endl;
        cout << " 5- Copy a part of the string from a certain position and specified length." << endl;
        cout << " 6- Swaps the first and second strings." << endl;
        cout << " 7- Concatenate the two strings and show the result." << endl;
        cout << " 8- Compare the length of the two strings" << endl;
        cout << " 9- Print a sub-string by starting and ending indexes." << endl;
        cout << "10- Trim the string." << endl;
        cout << "11- Turn all string characters to lowercase." << endl;
        cout << "12- Turn all string characters to uppercase." << endl;
        cout << "13- Return the index of the first occurrence of a specific character" << endl;
        cout << "14- Return the index of the last occurrence of a specific character" << endl;
        cout << "15- Show the string with a specific character changed to another" << endl;
        cout << "16- Exit the program." << endl;

        cin >> choice;
        cout << "====================================================" << endl;

        if(choice == 1)
        {
            cout << "First or second string. (1 | 2)" << endl << "--> ";
            cin >> whichString;
            if(whichString == 1)
            {
                cout << "str1 --> ";
                char* s = cinStr();
                MyString tempObj(s);
                str1 = tempObj;
                cout << "Done." << endl << endl;
            }
            else if(whichString == 2)
            {
                cout << "str2 --> ";
                char* s = cinStr();
                MyString tempObj(s);
                str2 = tempObj;
                cout << "Done." << endl << endl;
            }
            else
            {
                cout << "Wrong input." << endl << endl;
            }
        }
        else if(choice == 2)
        {
            cout << "First or second string. (1 | 2)" << endl << "--> ";
            cin >> whichString;
            if(whichString == 1)
            {
                str1.Remove();
                cout << "Last character removed." << endl << endl;
            }
            else if(whichString == 2)
            {
                str2.Remove();
                cout << "Last character removed." << endl << endl;
            }
            else
            {
                cout << "Wrong input." << endl << endl;
            }
        }
        else if(choice == 3)
        {
            cout << "Enter the new character." << endl << "--> ";
            cin.ignore(1);
            cin.get(newChr);

            cout << "First or second string. (1 | 2)" << endl << "--> ";
            cin >> whichString;
            if(whichString == 1)
            {
                str1.Add(newChr);
                cout << "New character has been added." << endl << endl;
            }
            else if(whichString == 2)
            {
                str2.Add(newChr);
                cout << "New character has been added." << endl << endl;
            }
            else
            {
                cout << "Wrong input." << endl << endl;
            }
        }
        else if(choice == 4)
        {
            cout << "str1: " << str1.Length() << endl;
            cout << "str2: " << str2.Length() << endl << endl;
        }
        else if(choice == 5)
        {
            cout << "Enter the position: ";
            cin >> pos;
            cout << "Enter the length: ";
            cin >> len;

            cout << "First or second string. (1 | 2)" << endl << "--> ";
            cin >> whichString;
            if(whichString == 1)
            {
                char* copiedStr = str1.Copy(pos, len);
                printString(copiedStr);
                cout << endl << endl;
            }
            else if(whichString == 2)
            {
                char* copiedStr = str2.Copy(pos, len);
                cout << "Result: ";
                printString(copiedStr);
                cout << endl << endl;
            }
            else
            {
                cout << "Wrong input." << endl << endl;
            }
        }
        else if(choice == 6)
        {
            str1.Swap(str2);
            cout << "Strings swapped." << endl << endl;
        }
        else if(choice == 7)
        {
            cout << "Result: " << str1+str2 << endl << endl;
        }
        else if(choice == 8)
        {
            cout << "Result: " << str1.Compare(str2) << endl << endl;
        }
        else if(choice == 9)
        {
            cout << "Enter start index: ";
            cin >> srtInx;
            cout << "Enter end index: ";
            cin >> endInx;

            cout << "First or second string. (1 | 2)" << endl << "--> ";
            cin >> whichString;
            if(whichString == 1)
            {
                cout << "Result: " << str1.SubString(srtInx, endInx) << endl;
            }
            else if(whichString == 2)
            {
                cout << "Result: " << str2.SubString(srtInx, endInx) << endl;
            }
            else
            {
                cout << "Wrong input." << endl << endl;
            }
        }
        else if(choice == 10)
        {
            cout << "First or second string. (1 | 2)" << endl << "--> ";
            cin >> whichString;
            if(whichString == 1)
            {
                cout << "Result: " << str1.Trim() << endl << endl;
            }
            else if(whichString == 2)
            {
                cout << "Result: " << str2.Trim() << endl << endl;
            }
            else
            {
                cout << "Wrong input." << endl << endl;
            }
        }
        else if(choice == 11)
        {
            cout << "First or second string. (1 | 2)" << endl << "--> ";
            cin >> whichString;
            if(whichString == 1)
            {
                cout << "Result: " << str1.ToLowerCase() << endl;
            }
            else if(whichString == 2)
            {
                cout << "Result: " << str2.ToLowerCase() << endl << endl;
            }
            else
            {
                cout << "Wrong input." << endl << endl;
            }
        }
        else if(choice == 12)
        {
            cout << "First or second string. (1 | 2)" << endl << "--> ";
            cin >> whichString;
            if(whichString == 1)
            {
                cout << "Result: " << str1.ToUpperCase() << endl;
            }
            else if(whichString == 2)
            {
                cout << "Result: " << str2.ToUpperCase() << endl << endl;
            }
            else
            {
                cout << "Wrong input." << endl << endl;
            }
        }
        else if(choice == 13)
        {
            cout << "Enter search character." << endl << "--> ";
            cin >> newChr;

            cout << "First or second string. (1 | 2)" << endl << "--> ";
            cin >> whichString;
            if(whichString == 1)
            {
                if(pos = str1.IndexOf(newChr))
                {
                    cout << "Result: " << pos << endl << endl;
                }
            }
            else if(whichString == 2)
            {
                if(pos = str2.IndexOf(newChr))
                {
                    cout << "Result: " << pos << endl << endl;
                }
            }
            else
            {
                cout << "Wrong input." << endl << endl;
            }
        }
        else if(choice == 14)
        {
            cout << "Enter search character." << endl << "--> ";
            cin >> newChr;

            cout << "First or second string. (1 | 2)" << endl << "--> ";
            cin >> whichString;
            if(whichString == 1)
            {
                if(pos = str1.LastIndexOf(newChr))
                {
                    cout << "Result: " << pos << endl << endl;
                }
            }
            else if(whichString == 2)
            {
                if(pos = str2.LastIndexOf(newChr))
                {
                    cout << "Result: " << pos << endl << endl;
                }
            }
            else
            {
                cout << "Wrong input." << endl << endl;
            }
        }
        else if(choice == 15)
        {
            cout << "Enter the old character." << endl << "--> ";
            cin >> oldChr;
            cin.clear();
            cout << "Enter the new character." << endl << "--> ";
            cin >> newChr;
            cin.clear();

            cout << "First or second string. (1 | 2)" << endl << "--> ";
            cin >> whichString;
            if(whichString == 1)
            {
                cout << newChr << "||" << oldChr<< endl;
                cout << "Result: " << str1.Replace(oldChr, newChr) << endl << endl;
            }
            else if(whichString == 2)
            {
                cout << "Result: " << str2.Replace(oldChr, newChr) << endl << endl;
            }
            else
            {
                cout << "Wrong input." << endl << endl;
            }
        }
        else if(choice == 16)
        {
            cout << "Exit..." << endl;
            break;
        }
        else if(choice == 0)
        {
            cout << "str1: " << str1 << endl;
            cout << "str2: " << str2 << endl;
        }
        else
        {
            cout << "Wrong input." << endl;
        }
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }


    return 0;
}
