export void Transpose(uniform const float a[], uniform float result[], uniform const int row_count, uniform const int col_count){
    foreach(i= 0...row_count, j = 0...col_count){
        result[j*row_count + i] = a[i*col_count + j];
    }
    return;
}