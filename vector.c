struct vector{
	double x;
	double y;
};
void vector_scale(struct vector* v, float scale){
	v->x *= scale;
	v->y *= scale;
}
float vector_length(struct vector* v){
	return sqrt(v->x * v->x + v->y * v->y);
}
void vector_add(struct vector* v1, struct vector* v2){
	v1->x += v2->x;
	v1->y += v2->y;

}
void vector_normalize(struct vector* v){
    double length = vector_length(v);
    vector_scale(v, 1.0/length); 
}
void vector_set_length(struct vector* v, float length){
	vector_normalize(v);
	vector_scale(v, length);
}
void vector_reverse(struct vector* v){
	v->x = -v->x;
	v->y = -v->y;
}