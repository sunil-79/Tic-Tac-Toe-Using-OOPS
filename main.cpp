#include<bits/stdc++.h>
using namespace std;

class Player
{
    public:
    string name;
    char symbol;

    Player()
    {
        this->name = " ";
        this->symbol = ' ';
    }

    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }

    void setSym(char symbol)
    {
        this->symbol = symbol;
    }

    char getSym()
    {
        return symbol;
    }

};

class Canvas{
    public:
    char board[3][3];
    Canvas()
    {
        for(int i = 0; i<3;i++)
        {
            for(int j =0; j<3;j++)
            {
                board[i][j] = ' ';
            }
        }
    }

    void display()
    {
        for(int i = 0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cout<<board[i][j]<<"|";
            }
            cout<<endl;
        }
    }

    void clear()
    {
        for(int i = 0; i<3; i++)
        {
            for(int j=0; j<3;j++)
            {
                board[i][j] = ' ';
            }
        }
    }

    void update(int r, int c, char symbol)
    {
        board[r][c] = symbol;
    }

    bool isFull()
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(board[i][j]==' ') return false;
            }
        }
        return true;
    }
};

class TicTacToe{
    public:
    
    Player arr[2];
    Canvas canvas; //matrix bani h

    TicTacToe()
    {
        for(int i =0; i<2; i++)
        {
            arr[i] = Player();
        }
        canvas = Canvas();
    }
    
    bool checkWin(Player p)
    {
        for(int i =0; i<3;i++)
        {
            if(canvas.board[i][0]==p.getSym() && canvas.board[i][1]==p.getSym() && canvas.board[i][2]==p.getSym()) return true;
            if(canvas.board[0][i]==p.getSym() && canvas.board[1][i]==p.getSym() && canvas.board[2][i]==p.getSym()) return true;
        }
        if(canvas.board[0][0]==p.getSym() && canvas.board[1][1]==p.getSym() && canvas.board[2][2]==p.getSym()) return true;
        if(canvas.board[0][2]==p.getSym() && canvas.board[1][1]==p.getSym() && canvas.board[2][0]==p.getSym()) return true;

        return false;
    }

    void play()
    {
        for(int i = 0; i<2; i++)
        {
            cout<<"Enter Player" <<i+1<<" Name : ";
            string p;
            char s;
            cin>>p;
            cout<<"Enter Player" << i+1 <<"Symbol : ";
            cin>>s;
            arr[i].setName(p);
            arr[i].setSym(s);
        }
        int i = 0;
        canvas.display();
        while(!canvas.isFull())
        {
            cout<<"Enter Row: ";
            int r;
            cin>>r;
            cout<<"Enter Col: ";
            int c;
            cin>>c;
            //isValid Function banana hai
            canvas.update(r,c,arr[i].getSym());
            canvas.display();
            if(checkWin(arr[i])) 
            {
                cout<<arr[i].getName()<<" is th Winner!!!!!"<<endl;
                return;
            }
            if(!i) i=1;
            else i=0;
        }
        cout<<"It's a Tie!!! \n Let's play another game"<<endl;
        canvas.clear();
        play();

    }


};




int main()
{
    TicTacToe t;
    t.play();
    return 0;
}