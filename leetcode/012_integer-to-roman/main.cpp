class Solution {
public:
    string intToRoman(int num) {
        string rs = "";
        int n = num;
        while (n >= 1000) {
            rs.append("M");
            n -= 1000;
        }
        
        int nHundrand = n/100;
        switch (nHundrand) {
            case 1: rs.append("C");    break;
            case 2: rs.append("CC");   break;
            case 3: rs.append("CCC");  break;
            case 4: rs.append("CD");   break;
            case 5: rs.append("D");    break;
            case 6: rs.append("DC");   break;
            case 7: rs.append("DCC");  break;
            case 8: rs.append("DCCC"); break;
            case 9: rs.append("CM");   break;
        }
        
        int nTen = (n - 100*nHundrand)/10;
        switch (nTen) {
            case 1: rs.append("X");    break;
            case 2: rs.append("XX");   break;
            case 3: rs.append("XXX");  break;
            case 4: rs.append("XL");   break;
            case 5: rs.append("L");    break;
            case 6: rs.append("LX");   break;
            case 7: rs.append("LXX");  break;
            case 8: rs.append("LXXX"); break;
            case 9: rs.append("XC");   break;
        }
        
        int nOne = n % 10;
        switch (nOne) {
            case 1: rs.append("I");    break;
            case 2: rs.append("II");   break;
            case 3: rs.append("III");  break;
            case 4: rs.append("IV");   break;
            case 5: rs.append("V");    break;
            case 6: rs.append("VI");   break;
            case 7: rs.append("VII");  break;
            case 8: rs.append("VIII"); break;
            case 9: rs.append("IX");   break;
        }
        
        return rs;
    }
};
