using namespace std;

long long solution(int price, int money, int count)
{
    long long totalPrice = price *((long long)count+1)*(count)/2;
    return (totalPrice-money>0? totalPrice-money:0);
}