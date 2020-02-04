/*
  https://www.urionlinejudge.com.br/judge/en/problems/view/1022
  
  Considering N1 and D1 as numerator and denominator of the first fraction, 
  follow the orientation about how to do each one of these 4 operations:

    Sum: (N1*D2 + N2*D1) / (D1*D2)
    Subtraction: (N1*D2 - N2*D1) / (D1*D2)
    Multiplication: (N1*N2) / (D1*D2)
    Division: (N1/D1) / (N2/D2), that means (N1*D2)/(N2*D1)  
*/  

#include <stdio.h>

typedef struct rational{
    long int N;
    long int D;
} rational;

int divisible(long int a, long int b, long int factor){
    return (a%factor == 0 && b%factor ==0) ? 1 : 0;
}
    
rational simplify(rational r){
    rational result = { r.N, r.D };    
    long int k = r.N <= r.D ? r.D : r.N;    
    int factor;
    for(factor=2; factor<k; factor++){
        while (divisible(result.N, result.D, factor)){
            result.N /= factor;
            result.D /= factor;
        }                      
        k = result.N < result.D ? result.N : result.D;
    }    
    return result;
}


int main(void){
    int N, i;
    char op, ignore;
    rational R1, R2, R3, RS;
    scanf(" %d", &N);
    for(i=0; i<N; i++){
        scanf(" %ld / %ld %c %ld / %ld", &R1.N, &R1.D, &op, &R2.N, &R2.D);
        //printf("%d/%d %c %d/%d --> ", R1.N, R1.D, op, R2.N, R2.D);
        switch(op){
            case '+':
                //Sum: (N1*D2 + N2*D1) / (D1*D2)
                R3.N = (R1.N*R2.D + R2.N*R1.D);
                R3.D = (R1.D*R2.D);                
                break;
            case '-':
                //Subtraction: (N1*D2 - N2*D1) / (D1*D2)
                R3.N = ((R1.N*R2.D) - (R2.N*R1.D));
                R3.D = (R1.D*R2.D);                
                break;
            case '*':
                //Multiplication: (N1*N2) / (D1*D2)
                R3.N = (R1.N*R2.N);
                R3.D = (R1.D*R2.D);
                break;
            case '/':
                //Division: (N1/D1) / (N2/D2), that means (N1*D2)/(N2*D1)  
                R3.N = (R1.N*R2.D);
                R3.D = (R2.N*R1.D);
                break;
        }
        RS = simplify( R3 );
        printf("%ld/%ld = %ld/%ld\n", R3.N, R3.D, RS.N, RS.D);
    }
}


