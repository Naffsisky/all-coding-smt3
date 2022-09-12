#include <stdio.h>

int main(){
int size;
printf("Masukan nilai dari array size : ");
scanf("%d", &size);
int arr[size];
for (int i=0; i<size; i++){
printf("Masukan nilai arr : ");
scanf("%d", &arr[i]);
}
for (int i=0; i<size; i++){
printf("Nilai array adalah : %d\n", arr[i]);
}
return 0;
}
