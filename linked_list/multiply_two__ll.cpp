//dono ll se phle number extract krlie...
//fir muktiple krdia...easy

//o(n+m)
//o(1)

class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
       
       
        long long num1=0;
        
        while(first){
            num1=(num1*10+first->data)%1000000007;
            first=first->next;
        }
        
        long long num2=0;
        
        while(second){
            num2=(num2*10+second->data)%1000000007;
            second=second->next;
        }
        
        
        return (num1*num2)%1000000007;
    }
};