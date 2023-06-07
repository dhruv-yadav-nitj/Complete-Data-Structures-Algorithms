
// cin stops taking input when a space or new character or tab character comes the way, so we use 
// cin.getline(str, len)

// https://www.codingninjas.com/codestudio/problems/replace-spaces_1172172

string replaceSpaces(string &str)
{
    string temp ;
    for (int i = 0; i < str.length() ; i++)
    {
        if (str[i]==' ')
        {
            temp += "@40" ;
        }
        else
        {
            temp += str[i] ;
        }        
    }
    return temp ;
}