import java.io.*;
import java.util.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;

public class Main { 


    /**
     *  Trim leading zeros
     *  and tailing zerors for decimal number
     */
    public static String trimZeros(String result) {
    
        int i = 0;
        // trim leading zeros
        while ('0' == result.charAt(i) && i < result.length()) i++;
        result = result.substring(i);

        // trim tailing zeros
        if (result.indexOf('.') != -1) {
            i = result.length() - 1;
            while (i >= 0 && '0' == result.charAt(i)) i--;
            result = result.substring(0, i+1);
            i = result.length() - 1;
            if ('.' == result.charAt(i)) {
                return result.substring(0, i);
            } else {
                return result;
            }
        } else {
            return result;
        }

    }

    public static void main(String args[]) throws Exception {

        Scanner cin = new Scanner(System.in);

        while (cin.hasNext()) {
            BigDecimal r = cin.nextBigDecimal();
            int n = cin.nextInt();
            String result = r.pow(n, MathContext.UNLIMITED).toPlainString();
            System.out.println(trimZeros(result));
        }

        cin.close();

    }
}

