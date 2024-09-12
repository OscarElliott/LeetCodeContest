class Solution 
{
public:
    string convertDateToBinary(string date) 
    {
        int year = (date[0]-'0')*1000+(date[1]-'0')*100+(date[2]-'0')*10+(date[3]-'0');
        int month = (date[5]-'0')*10+(date[6]-'0');
        int day = (date[8]-'0')*10+(date[9]-'0');
        string res = to_binary(year)+"-"+to_binary(month)+"-"+to_binary(day);
        return res;
    }

    string to_binary(int num)
    {
        string binary = "";
        while(num)
        {
            binary = (num % 2 == 0 ? "0" : "1") + binary;
            num /=2;
        }
        return binary;
    }
};