// define the relevant values at the start of your code beforehand
// #define lags <value> for the length of your autocorrelation vector
// #define min_lags <value> and #define max_lags <value> to define the interval over the vector that we are interested in

//make sure to subtract out the mean value from the data, such that the overall mean of the array is as close to 0 as possible
//autocorrelation function is very sensitive to non-zero mean, and ADCs exclusively output positive values

//Autocorrelation on rawdata array, preferably after filtering
  for(i=0;i<lags;i++)
  {
    for(j=0;j<n;j++)
    {
      if(i+j<n) autocorr[i]+=rawdata_HB[j]*rawdata_HB[i+j];
      else autocorr[i]+=rawdata_HB[j]*rawdata_HB[i+(n-j)];
    }
  }

  //Peak detection
  int peaklag_max=1; //do not set this to 0 as that may cause divide-by-zero errors later
  int peak_max=autocorr[min_lags];
  
  for(i=min_lags;i<max_lags;i++)
  {
    if(autocorr[i]>peak_max)
    {
      peak_max=autocorr[i];
      peaklag_max=i;
    }
  }
