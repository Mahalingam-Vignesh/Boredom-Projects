import java.util.Scanner;
import java.lang.*;

public class XO {
    
    public static StringBuilder ground = new StringBuilder("123\n456\n789");
    public static String winner;

    public static void drawBoard() {

        System.out.println(ground+"\n");

    }

    public static boolean check() {

        String x = "XXX";
        String o = "OOO";
        if((ground.substring(0,3).equals(x)) || (ground.substring(4,7).equals(x)) || (ground.substring(8,11).equals(x))) // Horizontal
        {
            winner = "X";
            return false;
        }
        else if((ground.substring(0,3).equals(o)) || (ground.substring(4,7).equals(o)) || (ground.substring(8,11).equals(o)) )
        {
            winner = "O";
            return false;
        }
        else if(ground.charAt(0) == ground.charAt(4))                   // vertical
        {
            if(ground.charAt(4) == ground.charAt(8))
            {
                if(ground.charAt(4)=='X')
                {
                    winner = "X";
                }
                else
                {
                    winner = "O";
                }
                return false;
            }
        }
        else if(ground.charAt(1) == ground.charAt(5))
        {
            if(ground.charAt(5) == ground.charAt(9))
            {
                if(ground.charAt(5)=='X')
                {
                    winner = "X";
                }
                else
                {
                    winner = "O";
                }
                return false;
            }
        }
        else if(ground.charAt(2) == ground.charAt(6))
        {
            if(ground.charAt(6) == ground.charAt(10))
            {
                if(ground.charAt(6)=='X')
                {
                    winner = "X";
                }
                else
                {
                    winner = "O";
                }
                return false;
            }
        }
        else if(ground.charAt(0) == ground.charAt(5))                   // Diagonal
        {
            if(ground.charAt(5) == ground.charAt(10))
            {
                if(ground.charAt(5)=='X')
                {
                    winner = "X";
                }
                else
                {
                    winner = "O";
                }
                return false;
            }
        }
        else if(ground.charAt(2) == ground.charAt(5))
        {
            if(ground.charAt(5) == ground.charAt(8))
            {
                if(ground.charAt(5)=='X')
                {
                    winner = "X";
                }
                else
                {
                    winner = "O";
                }
                return false;
            }
        }
        return true;

    }

    public static void main(String arg[]) {

        Scanner a = new Scanner(System.in);
        System.out.println("Welcome to the XO game\n");
        boolean game = true;
        int count = 0;
        int b;
        char c;

        while(game)
        {
            drawBoard();
            if(count%2 ==0)    // X turn
            {
                c = 'X';
            }
            else               // O turn
            {
                c = 'O';
            }
            System.out.println("Enter the position for " + c +":\t");
            b = a.nextInt();
            if((b>=1) && (b<=9))
            {
                if((b>=1) && (b<=3))
                {
                    b = b - 1;
                }
                else if((b>=7)&&(b<=9))
                {
                    b = b + 1;
                }
                if((ground.charAt(b)=='X') || (ground.charAt(b)=='O'))
                {
                    System.out.println("You cannot place it there.\n");
                    continue;
                }
                ground.setCharAt(b,c);
            }
            else
            {
                System.out.println("Invalid input. Please Note to give input between 0 and 9\n");
                continue;
            }
            count++;
            if(count==9)
            {
                game = false;
            }
            if(count>=3)
            {
                game = check();             // to check for winner
            }
        }

        drawBoard();
        if(winner != null)
        {
            System.out.println("The Winner of the match is "+winner);
        }
        else
        {
            System.out.println("It is draw.");
        }
    }
}

/* Description of the code:

    A StringBuilder is created named ground, which is the board of the play.
    An integer named b, is fetched for positioning X and O.
    The function check checks for the winning requirement.
    It sets the boolean named game false, if the winning requirement is met. 
    The variable controls the game flow and escapes the while loop, if the winning requirement is met.
    Or else, the game is played until, the board is filled up.                                              */


/*	Behind the code:

	Mahalingam Vignesh N P's version of cliche.
	Time Taken : 1 hour.
	If you find any suggestion, feel free to email : npmlvignesh10@gmail.com								*/