
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main {

    static class info{
        int x,y,speed,dir,size;

        public info(int x, int y, int speed, int dir, int size) {
            super();
            this.x = x;
            this.y = y;
            this.speed = speed;
            this.dir = dir;
            this.size = size;
        }
    }

    static int R,C,M, ans=0;
    static int [][] map, copy;
    static int [] dx = {0,-1,1,0,0};
    static int [] dy = {0,0,0,1,-1};

    static ArrayList<info> shark = new ArrayList<>();
    static Queue<Integer> remove = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken()); //X
        C = Integer.parseInt(st.nextToken()); //Y
        M = Integer.parseInt(st.nextToken()); //상어 수

        map = new int[R+1][C+1];

        for(int i=0;i<M;i++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());

            shark.add(new info(r,c,s,d,z));
            map[r][c] = z;
        }


        for(int i=1;i<=C;i++) {
            //상어잡기
            sharkCatch(i);
            //상어움직이기
            sharkMove();
        }
        System.out.println(ans);

    }

    public static void print() {
        for(int i=1;i<R+1;i++) {
            for(int j=1;j<C+1;j++) {
                System.out.print(map[i][j]+" ");
            }
            System.out.println();
        }
    }

    public static void sharkCatch(int y) {
        Loop:
        for(int x=1;x<R+1;x++) {
            if(map[x][y]!=0) {
                for(int i=0;i<shark.size();i++) {
                    if(shark.get(i).x==x && shark.get(i).y==y) {
                        ans+=shark.get(i).size;
                        map[x][y]=0;
                        shark.remove(i);
                        break Loop;
                    }
                }
            }
        }
    }

    public static void sharkMove() {

        copy = new int[R+1][C+1];

        for (int i=0;i<shark.size();i++) {
            info temp = shark.get(i);

            map[temp.x][temp.y] = 0;

            for (int j = 0; j < temp.speed ; j++) {// d==1 상, d==2 하, d==3 우, d==4 좌

                if (temp.dir == 1 && temp.x == 1) temp.dir = 2;
                else if (temp.dir == 2 && temp.x == R)temp.dir = 1;
                else if (temp.dir == 3 && temp.y == C)temp.dir = 4;
                else if (temp.dir == 4 && temp.y == 1)temp.dir = 3;

                temp.x += dx[temp.dir];
                temp.y += dy[temp.dir];
            } //상어 이동 끝

            if(copy[temp.x][temp.y]==0) {
                copy[temp.x][temp.y] = temp.size;
            }else if(copy[temp.x][temp.y]<temp.size) { //움직인 상어가 기존에 있던 상어보다 큰 경우
                remove.add(copy[temp.x][temp.y]);
                copy[temp.x][temp.y] = temp.size;
            }else {
                remove.add(temp.size);
            }
        }

        while(!remove.isEmpty()) {
            int temp = remove.poll();
            for(int i=0;i<shark.size();i++) {
                if(temp==shark.get(i).size) {
                    shark.remove(i); break;
                }
            }
        }
        map = copy;
    }

}