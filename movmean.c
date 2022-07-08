//this code is very similar in functioning to movmean in MATLAB, with a moving average of window 1 to W until window length is reached
//this approach preserves the initial stream of data and prevents needless attenuation from zero-padding

//initial filtering with moving average
//use #define filter_window <value> and #define n <value> at the start of your code
// rawdata_HB is the recoreded array, and size n is previously defined

  int wmov = filter_window;
  int summ=0;
  int16_t movmean[wmov];
  int iter;
  
  for(int i=0; i<wmov; i++)
  {
  movmean[i]=rawdata_HB[i];
  summ = summ+rawdata_HB[i];
  rawdata_HB[i] = round( float(summ)/float(i+1) );
  }
  
  float val = float(summ)/float(wmov);
  
  for(int i=wmov; i<n; i++)
  {
  iter=i%wmov;
  val = ((val*wmov)+(rawdata_HB[i]-movmean[iter]))/float(wmov);
  movmean[iter]=rawdata_HB[i];
  rawdata_HB[i]=round(val);
  }
  
