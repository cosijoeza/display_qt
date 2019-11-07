/*NEGATIVO de una imagen*/
Mat negative(Mat img)
{
    Mat imneg = img.clone();
    int nCanales = img.channels();
    int nRen = img.rows;
    int nCol = img.cols * nCanales;
    int x,y=0;
    for(x = 0; x < nRen; x++)
    {    
        uchar *renglon  = img.ptr<uchar>(x); 
        uchar *negativo = imneg.ptr<uchar>(x);
        for(y = 0; y < nCol; y++)
        {
            *(negativo + y) = ~(*(renglon + y));
        }
    }
    return imneg;
}
/*Operacion AND*/
Mat funAnd(Mat img1,Mat img2)
{
    Mat imand = img1.clone();
    int nCanales = img1.channels();
    int nRen = img1.rows;
    int nCol = img1.cols * nCanales;
    int x,y=0;
    for(x = 0; x < nRen; x++)
    {    
        uchar *renglon_1  = img1.ptr<uchar>(x);
        uchar *renglon_2  = img2.ptr<uchar>(x); 
        uchar *pand = imand.ptr<uchar>(x);
        for(y = 0; y < nCol; y++)
        {
            *(pand + y) = *(renglon_1 + y) & *(renglon_2 + y);
        }
    }
    return imand;
}
/*Operacion OR*/
Mat funOr(Mat img1,Mat img2)
{
    Mat imor = img1.clone();
    int nCanales = img1.channels();
    int nRen = img1.rows;
    int nCol = img1.cols * nCanales;
    int x,y=0;
    for(x = 0; x < nRen; x++)
    {    
        uchar *renglon_1  = img1.ptr<uchar>(x);
        uchar *renglon_2  = img2.ptr<uchar>(x); 
        uchar *por = imor.ptr<uchar>(x);
        for(y = 0; y < nCol; y++)
        {
            *(por + y) = *(renglon_1 + y) | *(renglon_2 + y);
        }
    }
    return imor;
}
/*Operacion RESTA*/
Mat funResta(Mat img1,Mat img2)
{
    Mat imresta = img1.clone();
    int nCanales = img1.channels();
    int nRen = img1.rows;
    int nCol = img1.cols * nCanales;
    int x,y=0;
    for(x = 0; x < nRen; x++)
    {    
        uchar *renglon_1  = img1.ptr<uchar>(x);
        uchar *renglon_2  = img2.ptr<uchar>(x); 
        uchar *pres = imresta.ptr<uchar>(x);
        for(y = 0; y < nCol; y++)
        {
            *(pres + y) = abs( *(renglon_1 + y) - *(renglon_2 + y) );
            //cout << "Resta " << int(*(pres + y)) << endl;
        }
    }
    return imresta;
}
/*Operacion RESTA NORMALIZADA*/
Mat funRestaNorm(Mat img1,Mat img2)
{
    Mat imresta = img1.clone();
    int nCanales = img1.channels();
    int nRen = img1.rows;
    int nCol = img1.cols * nCanales;
    int x,y=0,minimo = 1000,maximo =-1000,resultado;
    //Obtener valor maximo y minimo de la RESTA entre imagenes
    for(x = 0; x < nRen; x++)
    {    
        uchar *renglon_1  = img1.ptr<uchar>(x);
        uchar *renglon_2  = img2.ptr<uchar>(x);
        uchar *pres  =imresta.ptr<uchar>(x);
        for(y = 0; y < nCol; y++)
        {
            resultado = *(renglon_1 + y) - *(renglon_2 + y);
            *(pres + y) = resultado;
            if(resultado > maximo)
                maximo = resultado;
            else
                minimo = resultado;
        }
    }
    //Normalizar imagen
    for(x = 0; x < nRen; x++)
    {    
        uchar *pres = imresta.ptr<uchar>(x);
        for(y = 0; y < nCol; y+=nCanales)
        {
            if(maximo == minimo)
                *(pres + y) = 0;
            else    
                *(pres + y) =  int( (*(pres + y) - minimo) / ((maximo - minimo) * 1.0) * 255);
        }
    }
    return imresta;
}
/*Operacion SUMA NORMALIZADA*/
Mat funSuma(Mat img1,Mat img2)
{
    Mat imsuma = img1.clone();
    int nCanales = img1.channels();
    int nRen = img1.rows;
    int nCol = img1.cols * nCanales;
    int x,y=0,maximo =-1000,resultado;
    //Obtener valor maximo de la SUMA entre imagenes
    for(x = 0; x < nRen; x++)
    {    
        uchar *renglon_1  = img1.ptr<uchar>(x);
        uchar *renglon_2  = img2.ptr<uchar>(x);
        uchar *psum  = imsuma.ptr<uchar>(x);
        for(y = 0; y < nCol; y++    )
        {
            resultado = *(renglon_1 + y) + *(renglon_2 + y);
            *(psum + y) = resultado;
            if(resultado > maximo)
                maximo = resultado;
        }
    }
    //Normalizar imagen
    for(x = 0; x < nRen; x++)
    {    
        uchar *psum = imsuma.ptr<uchar>(x);
        for(y = 0; y < nCol; y+=nCanales)
        {    
            *(psum + y) =  int( (*(psum + y) * 255) / (maximo * 1.0) );
        }
    }
    return imsuma;
}
// Funcion para obtener los canales de una imagen
Mat funGetChannel(Mat img,int bgr)
{
    //Verificar que las imagenes se lean en RGB
    Mat canal = img.clone();
	int nCan = canal.channels();
	int nRen = img.rows;
	int nCol = img.cols * nCan;
	int c1 = 0,c2 = 0;
    int x,y;
    switch(bgr)
    {
        case 0: //BLUE
            c1 = 1;
            c2 = 2;
            break;
        case 1: //GREEN
            c1 = 0;
            c2 = 2;
            break;  
        case 2: //RED
            c1 = 0;
            c2 = 1;
            break;
    }
    for(x = 0; x < nRen; x++)
    {
        uchar *renglon = canal.ptr<uchar>(x);
        for(y =0; y < nCol; y+=nCan)
        {
            *(renglon + y + c1) = 0;
            *(renglon + y + c2) = 0;
        }
    }   
    return canal;
}
/*Escalamiento*/
Mat escala(Mat img,int porcentaje)
{
    int i,j,x,y;
    int nRen = img.rows;
    int nCol = img.cols;
    int new_Ren = ceil(nRen / (porcentaje*1.0));
    int new_Col = ceil(nCol / (porcentaje*1.0));
    Mat new_image = Mat::zeros(new_Ren,new_Col,CV_8UC1);
    for(x = 0,i = 0; x < nRen; x+=porcentaje,i++)
	{
        uchar * pixelA = img.ptr<uchar>(x);
		uchar * pixelB = new_image.ptr<uchar>(i);
        for( y = 0,j = 0; y < nCol; y+=porcentaje,j++)
		{
			*(pixelB + j) = *(pixelA + y);
		}
    }
    return new_image;
}

Mat traslation(Mat img,int direction,int px)
{
    int x,y,dy,dx; 
    int nCanales = img.channels();
  	int nRen = img.rows;
  	int nCol = img.cols*nCanales;
	Mat new_image = Mat::zeros(nRen,nCol,CV_8UC1);
    if(direction == 0)
    {
        dy = px;
        /*Eje de las x*/
        if(dy > 0)
        {
            for(x = 0; x < nRen; x++)
            {
                uchar * pixelA = img.ptr<uchar>(x); 
                uchar * pixelB = new_image.ptr<uchar>(x);
                for(y = 0; (y + dy) < nCol; y+=nCanales)
                { *(pixelB + (y+dy)) = *(pixelA + y); } 
            }    
        }else/*0 < px*/
        {
            dy *= -1; 
        	for(x = 0; x < nRen; x++)
		  	{
		  		uchar * pixelA = img.ptr<uchar>(x); 
		  		uchar * pixelB = new_image.ptr<uchar>(x);
		  		for(y = 0; (y + dy) < nCol; y+=nCanales)
		  		{ *(pixelB + y) = *(pixelA + (dy+y)); } 
		  	}
        }
        
    }else
    {
        /*Eje de las y*/
        dx = px; //Diferencia de pixeles
		if(dx > 0)
        {
            for(x = 0; (x+dx) < nRen; x++)
		    {
		  	    uchar * pixelA = img.ptr<uchar>(x + dx); 
		  	    uchar * pixelB = new_image.ptr<uchar>(x);
		  	    for(y = 0; y < nCol; y++)
		  	    { *(pixelB + y) = *(pixelA + y); } 
		    }
        }else
        {
            dx *= -1;
            for(x = 0; (x + dx) < nRen; x++)
		  	{
		  		uchar * pixelA = img.ptr<uchar>(x); 
		  		uchar * pixelB = new_image.ptr<uchar>(x+dx);
		  		for(y = 0; y < nCol; y++)
		  		{ *(pixelB + y) = *(pixelA + y); } 
		  	}
        }
        
    }
    return new_image;
}
void rota(int v, void *Datos)
{    
    //Informacion de la imagen
    int nc = imWB.channels();
    int rw = imWB.rows;
    int cl = imWB.cols*nc;
    //Variables para la rotacion
    int xReference,yReference,i,j,k;
    int newX,newY,x,y;

    int newR =  ( rw*abs(COS(v)) + cl*abs(SIN(v)));
    int newC =  ( rw*abs(SIN(v)) + cl*abs(COS(v)));

    Mat res = Mat::zeros(newR,newC,imWB.type());

	xReference = newR/2;
    yReference = newC/2;

    int xoffset = xReference - rw/2;
    int yoffset = yReference - cl/2;

    //Calculo de la rotacion de la imagen
    for(j=0; j < rw ;j++){
        uchar *ren = imWB.ptr< uchar > (j);
        for (i = 0; i < cl; i+=nc){
            for(k=0; k < nc; ++k){
                newX = j - xReference + xoffset;
                newY = i - yReference + yoffset;
                x =  xReference + ( newX*COS(v) - newY*SIN(v));
                y =  yReference + ( newX*SIN(v) + newY*COS(v));
                if(x>=0 && x < newR && y>=0 && y < newC){
                    uchar *renc = res.ptr< uchar > (x);
                    *(renc + y + k) = *(ren + i + k);
                }
            }
        }
    }
    namedWindow("Rotacion", 1);
    imshow("Rotacion", res);
}