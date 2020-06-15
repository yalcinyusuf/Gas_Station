/*Yusuf YALÇIN 
18120205032 
Proje2
Divide and Conquer kısmında merge ve mergesort kısmında internet kaynağından yardım aldım kendi yorumumu da katarak zaten asıl işi kendim yaptım,küçük bir kısmı.
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

float mList[15] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150}; //başlangıç noktasına mesafeler(km), gideceğimiz yer ise 160.km de olsun
float pList[15] = {5,10,20,8,30,10,15,20,23,18,24,30,27,14,11}; //tl cinsinden fiyatlar
int Limit  = 20;  //k değişkeni olarak tanımlanan minimum durma uzaklığı(km)
int F = 50; //Bir depo ile gidilebilecek maksimum uzaklık(km)
int distance = 0;
int mesafe = 0;
int yer = 0;
int fiyat = 0;
int depo = 0;
int p_random = 0;
int yer1 = 0;
int fiyat1 = 0;
int distance2 = 0;

int randomGitme(){
    srand(time(NULL));
    
     while(depo < 160){
        distance =  rand()%31+20;
    if(distance < 30){
        depo += 20;
        for(int i=0;i<15;i++){
            if(mList[i]==depo)
            p_random += pList[i];
        }
    }
    else if(distance < 40){
        depo += 30;
        for(int i=0;i<15;i++){
            if(mList[i]==depo)
            p_random += pList[i];
        }
    }
     else if(distance<50){
        depo += 40;
        for(int i=0;i<15;i++){
            if(mList[i]==depo)
            p_random += pList[i];
        }
    }
    else {
        depo += 50;
          for(int i=0;i<15;i++){
            if(mList[i]==depo)
            p_random += pList[i];
        }
    }
     if(depo >=160){
            break;
        }
    }
    return p_random;
}
int BruteForce(){
    clock_t start_t, end_t;
    int p_toplam20 = 0;
    
    start_t = clock();
    randomGitme();
    distance = 0;
    for (int i = 0; i < 15; i++)//20 km 20 km gitme(Limit) en kötü ihtimal olma ihtimali en yüksek
    {
       if(Limit <= mList[i]-distance){
           distance = mList[i];
           p_toplam20 += pList[i];
            if(distance == 160){
                break;
           }
       }
       else{
           if(distance == 140){
               distance += 20;
               break;
           }
           continue;
       }
    }
    end_t = clock();
    printf("\nstart_t değeri: %ld\n", start_t);
    printf("end_t değeri: %ld\n", end_t);
    printf("Brute Force CPU süreci (saniye): %f\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
    if(randomGitme() < p_toplam20) 
    return randomGitme();
    return p_toplam20;
}
float min()
{   
    float mins;
    mins = pList[1]/mList[1]; 
    for(int i=(mesafe/10);i<(mesafe+F)/10;i++){
        if(Limit <= mList[i]-mesafe){
          if((pList[i]/mList[i])<mins){ 
            mins = pList[i]/mList[i];
             yer = mList[i];
          }
        }else{
       
          continue;
        }
        if(mins == pList[i]/mList[i] ){
        yer = mList[i];
        fiyat = pList[i];
        }
    }
    return yer;
}
int Greedy(){
    int fiyat_top = 0;
    clock_t start_t, end_t;
    start_t = clock();
    while(mesafe < 120){
    min();
    mesafe = yer;
    fiyat_top += fiyat;
    }
    end_t = clock();
    printf("\nstart_t değeri: %ld\n", start_t);
    printf("end_t değeri: %ld\n", end_t);
    printf("Greedy CPU süreci (saniye): %f\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
    return fiyat_top;
}
void merge(float arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
 
void mergeSort(float arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
void helpArray(float A[], int size) 
{ 
    
    for (int i=0; i < size; i++) { 
        for(int j= 0; j < size; j++){
        if(A[i]==pList[j]){
         if(Limit <= mList[j]-distance2 && mList[j] <= F+distance2){
             yer1 = mList[j];
             fiyat1 = pList[j];
         }
        }
        else{
            continue;
        }
    }
    }
} 
int divideAndConquer(){
    clock_t start_t, end_t;
    start_t = clock();
    int fiyat_top2 = 0;
    int arr_size = sizeof(pList)/sizeof(pList[0]); 
    while(yer1 < 120){
    mergeSort(pList, 0, arr_size - 1); 
    helpArray(pList, arr_size); 
    distance2 = yer1;
    fiyat_top2 += fiyat1;
    }
    end_t = clock();
    printf("\nstart_t değeri: %ld\n", start_t);
    printf("end_t değeri: %ld\n", end_t);
    printf("Greedy CPU süreci (saniye): %f\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
    return fiyat_top2;
}
int main(){
    printf("Brute force ile benzin maliyetimiz :%d\n",BruteForce());
    printf("Greedy ile benzin maliyetimiz :%d\n",Greedy());
    printf("Divide and Conquer ile benzin maliyetimiz :%d\n",divideAndConquer());

    return 0;
}
