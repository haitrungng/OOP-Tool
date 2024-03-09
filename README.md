# OOP-Tool
using for creating get&amp;set function

1. for c++

INPUT:
{

    string ten;
    string DOB;
    int tuoi;

}

OUTPUT:
{

    string getTen(){return ten; }
    void setTen(string TEMPORARY){ ten= TEMPORARY;}
    string getDOB(){return DOB; }
    void setDOB(string TEMPORARY){ DOB= TEMPORARY;}
    int getTuoi(){return tuoi; }
    void setTuoi(int TEMPORARY){ tuoi= TEMPORARY;}

}

2. for JAVA

INPUT:
{

    private double balance;
    private String name;

}

OUTPUT:
{

    public double getBalance(){return balance; }
    public void setBalance(double TEMPORARY){ balance= TEMPORARY;}
    public String getName(){return name; }
    public void setName(String TEMPORARY){ name= TEMPORARY;}

}

3. for JS

INPUT:
{

    this.width = width
    this.height = height

}

OUTPUT:
{
    get width(){ return this._width}
    set width(TEMPORARY){
        if(TEMPORARY > 0)    
            this._width = TEMPORARY
        else 
            console.error(`width must be a positive number`)
        }
    get height(){ return this._height}
    set height(TEMPORARY){
        if(TEMPORARY > 0)    
            this._height = TEMPORARY
        else 
            console.error(`height must be a positive number`)
        }

}
