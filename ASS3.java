import java.util.Scanner;

class Node2 {
    int element, update, location;
    Node2(int ele)
    {
        element = ele;
        update = 0;
        location = -1;
    }
}

class Task3 {
    int miss, hit, frameSize, n;
    
    Scanner sc = new Scanner(System.in);
    int A[];    // array for string
    int Frame[];    //array fro frame
    Node2 Frame2[];
    public void getData() {
        System.out.println("Enter The no of bits in input string : ");
        n = sc.nextInt();
        A = new int[n];
        for(int i = 0; i <n; i++) {
            System.out.println("Enter "+ (i+1) + " Bit : ");
            A[i] = sc.nextInt();
        }
        
        System.out.println("Enter the Frame Size : ");
        frameSize = sc.nextInt();
        Frame = new int[frameSize];
        Frame2 = new Node2[frameSize];
    }
    public void displayData() {
        System.out.println("Miss = " + miss);
        System.out.println("Hit = " + hit);
        System.out.println("Page Fault = " + miss);
    }

    public void Intialize() {
        for(int i = 0; i <frameSize; i++)
        {
            Frame2[i] = new Node2(-1);
        }
    }

    public void FIFO() {
        miss=1;
        hit=0;
        int count = 0;
        for(int i = 0; i <frameSize; i++)
        {
            Frame[i] = -1;
        }
        Frame[0] = A[0];
        for(int i=1; i<n; i++) 
        {
            boolean flag = false;
            for(int j=0; j<frameSize; j++)
            {
                if(A[i] == Frame[j])
                {
                    hit++;
                    flag = true;
                    break;
                }
                else if(Frame[j] == -1)
                {
                    Frame[j] = A[i];
                    miss++;
                    break;
                }
                if(flag == false)
                {
                    if(j == frameSize-1)
                    {
                        Frame[count] = A[i];
                        miss++;
                        count++;
                        if(count == frameSize-1)
                        {
                            count = 0;
                        }
                        break;
                    }
                }
            }
        }
    }

    public void LRU() {
        miss=1;
        hit=0;
        int cnt = 1;
        Frame2[0].element = A[0];
        for(int i=1; i<n; i++)
        {
            boolean flag = false;
            for(int p=0; p<cnt; p++)
            {
                Frame2[p].update++;
            }
            for(int j=0; j<frameSize; j++)
            {
                if(A[i] == Frame2[j].element)   // hit;
                {
                    Frame2[j].update = 0;
                    hit++;
                    flag = true;
                    break;
                }

                else if(Frame2[j].element == -1)    // empty
                {
                    Frame2[j].element = A[i];
                    Frame2[j].update = 0;
                    miss++;
                    cnt++;
                    break;
                }
                if(flag == false)
                {
                    if(j == frameSize-1)
                    {

                        int max = Frame2[0].update;
                        int index = 0;
                        for(int k=1; k<frameSize; k++)
                        {
                            if(max < Frame2[k].update)
                            {
                                max = Frame2[k].update;
                                index = k;
                            }
                        }
                        Frame2[index].element = A[i];
                        Frame2[index].update = 0;
                        miss++;
                        break;

                    }
                }
            }
        }
    }

    public void MRU() {
        miss=1;
        hit=0;
        for(int i = 0; i <frameSize; i++)
        {
            Frame[i] = -1;
        }
        Frame[0] = A[0];
        for(int i=1; i<n; i++) 
        {
            int MR = A[i-1];
            boolean flag = false;
            for(int j=0; j<frameSize; j++)
            {
                if(A[i] == Frame[j])
                {
                    hit++;
                    flag = true;
                    break;
                }
                else if(Frame[j] == -1)
                {
                    Frame[j] = A[i];
                    miss++;
                    break;
                }
                if(flag == false)
                {
                    if(j == frameSize-1)
                    {
                        for(int k=0; k<frameSize; k++)
                        {
                            if(Frame[k] == MR)
                            {
                                Frame[k] = A[i];
                                miss++;
                                break;
                            }
                        }
                        
                    }
                }
            }
        }
    }

    public void Optimal() {
        miss=1;
        hit=0;
        //insert first string bit in frame
        Frame2[0].element = A[0];
        for(int i=1; i<n; i++) 
        {
            boolean flag = false;
            for(int j=0; j<frameSize; j++)
            {
                if(A[i] == Frame2[j].element) //match
                {
                    hit++;
                    flag = true;
                    break;
                }
                else if(Frame2[j].element == -1)    //emmpty
                {
                    Frame2[j].element = A[i];
                    miss++;
                    break;
                }
                if(flag == false)   // not present
                {
                    if(j == frameSize-1)    // condition for miss
                    {
                        for(int k=0; k<frameSize; k++) // location in future
                        {
                            for(int p=i+1; p<n; p++)
                            {
                                if(Frame2[k].element==A[p])
                                {
                                    Frame2[k].location = p;
                                    break;
                                }
                                else if(Frame2[k].location == -1 && p==(n-1))
                                {
                                    Frame2[k].location = Integer.MAX_VALUE;
                                }
                            }
                        }

                        //finding max location

                        int max = Frame2[0].location;
                        int index = 0;
                        for(int m=1; m<frameSize; m++)
                        {
                            if(max < Frame2[m].location)
                            {
                                max = Frame2[m].location;
                                index = m;
                            }
                        }
                        Frame2[index].element = A[i];
                        miss++;
                        break;
                        
                    }
                }
            }
        }
    }
}

class ASS3 {
    public static void main(String[] args) {
        int ch;
        Task3 obj = new Task3();
        Scanner sc = new Scanner(System.in);
        obj.getData();
        do {
            System.out.println("1 : FIFO");
            System.out.println("2 : LRU");
            System.out.println("3 : MRU");
            System.out.println("4 : OPTIMAL REPLACEMENT");
            System.out.println("5 : EXIT");
            System.out.println("Enter The Choice : ");
            ch = sc.nextInt();

            switch (ch) {

                case 1:
                    System.out.println("-------------------FIFO --------------------");
                    obj.FIFO();
                    obj.displayData();
                    break;

                case 2:
                    System.out.println("-------------------LRU --------------------");
                    obj.Intialize();
                    obj.LRU();
                    obj.displayData();
                    break;

                case 3:
                    System.out.println("-------------------MRU --------------------");
                    obj.MRU();
                    obj.displayData();
                    break;

                case 4:
                    System.out.println("-------------------OPTIMAL REPLACEMENT --------------------");
                    obj.Intialize();
                    obj.Optimal();
                    obj.displayData();
                    break;

                case 5 :
                    System.out.println("End Of Program");
                    System.exit(0);

            }
        }while(ch<=5);
        
    }
}