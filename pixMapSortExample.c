void pixMap_sort(pixMap *p){
	qsort(p->image,p->width->p->height,sizeof(rgba),pixMap_cmp);
}
static int pixMap_cmp(const void *a, const void *b){
 const rgba *ra =(rgba*) a;
 const rgba *rb =(rgba*) b;
 return(ra->r - rb->r);
}
