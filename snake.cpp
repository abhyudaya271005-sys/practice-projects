#include <iostream>
#include <vector>
#include <deque>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Point { int x,y; };
enum Direction { UP,DOWN,LEFT,RIGHT };

class SnakeGame {
private:
    int width,height;
    deque<Point> snake;
    Point food;
    Direction dir;
    bool gameOver;
    int score;

public:
    SnakeGame(int w=30,int h=15):width(w),height(h),gameOver(false),score(0){
        srand(static_cast<unsigned>(time(nullptr)));
        int cx=width/2,cy=height/2;
        snake.push_back({cx,cy});
        snake.push_back({cx-1,cy});
        snake.push_back({cx-2,cy});
        dir=RIGHT;
        placeFood();
    }

    void run(){
        while(!gameOver){
            input();
            update();
            render();
            Sleep(100);
        }
        cout<<"\nGame Over! Final Score: "<<score<<"\n";
    }

private:
    void placeFood(){
        while(true){
            Point p{rand()%width,rand()%height};
            if(!isSnake(p)){ food=p; break; }
        }
    }

    bool isSnake(const Point& p){
        for(const auto& s:snake){
            if(s.x==p.x&&s.y==p.y) return true;
        }
        return false;
    }

    void input(){
        if(_kbhit()){
            int ch=_getch();
            if(ch==224){
                ch=_getch();
                if(ch==72&&dir!=DOWN) dir=UP;
                else if(ch==80&&dir!=UP) dir=DOWN;
                else if(ch==75&&dir!=RIGHT) dir=LEFT;
                else if(ch==77&&dir!=LEFT) dir=RIGHT;
            } else {
                if((ch=='w'||ch=='W')&&dir!=DOWN) dir=UP;
                else if((ch=='s'||ch=='S')&&dir!=UP) dir=DOWN;
                else if((ch=='a'||ch=='A')&&dir!=RIGHT) dir=LEFT;
                else if((ch=='d'||ch=='D')&&dir!=LEFT) dir=RIGHT;
                else if(ch=='q'||ch=='Q') gameOver=true;
            }
        }
    }

    void update(){
        Point head=snake.front();
        switch(dir){
            case UP: head.y-=1; break;
            case DOWN: head.y+=1; break;
            case LEFT: head.x-=1; break;
            case RIGHT: head.x+=1; break;
        }
        if(head.x<0||head.x>=width||head.y<0||head.y>=height){ gameOver=true; return; }
        if(isSnake(head)){ gameOver=true; return; }
        snake.push_front(head);
        if(head.x==food.x&&head.y==food.y){
            score+=10;
            placeFood();
        } else {
            snake.pop_back();
        }
    }

    void render(){
        system("cls");
        cout<<'+';
        for(int i=0;i<width;++i) cout<<'-';
        cout<<"+\n";
        for(int y=0;y<height;++y){
            cout<<'|';
            for(int x=0;x<width;++x){
                if(x==food.x&&y==food.y) cout<<'*';
                else if(snake.front().x==x&&snake.front().y==y) cout<<'O';
                else if(isSnake({x,y})) cout<<'o';
                else cout<<' ';
            }
            cout<<"|\n";
        }
        cout<<'+';
        for(int i=0;i<width;++i) cout<<'-';
        cout<<"+\n";
        cout<<"Score: "<<score<<"   ";
        cout<<"Controls: WASD or Arrow Keys | Quit: Q\n";
    }
};

int main(){
    SnakeGame game(40,20);
    game.run();
    return 0;
}