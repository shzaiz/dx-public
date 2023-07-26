// We need a tmp array to store relations...
void mgsort(int a[], int tmp[], int l, int r){
    if(l>=r) return ;
    //(1)
    int mid = (l+r)>>1; // Bracket missing is also okay.
    mgsort(a, tmp, l, mid);
    mgsort(a, tmp, mid+1, r);
    int k = 0, i = l, j = mid+1;
    // merge
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            tmp[k++] = a[i++];
        }else{
            tmp[k++] = a[j++];
        }
    }
    // Is there anything missing in the loop?
    while(i<=mid) tmp[k++] = a[i++];
    while(j<=r) tmp[k++] = a[j++];
    for(i=l,j=0; i<=r; i++, j++) a[i] = tmp[j];
}