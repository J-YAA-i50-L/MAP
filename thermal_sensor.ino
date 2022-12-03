int i = 0;
float v, t, r;
int mt[29];
float mr[29] = {181.70, 133.30, 98.88, 74.10, 56.06, 42.80, 32.96, 25.58,
      20.00, 15.76, 12.51, 10.00, 8.048, 6.518, 5.312, 4.354, 
      3.588, 2.974, 2.476, 2.072, 1.743, 1.473, 1.250, 1.065, 
      0.911, 0.782, 0.6744, 0.5836, 0.5066}; 

void setup() {
  pinMode(A0, INPUT);
   Serial.begin(9600);
   for(int j=0; j<29; j++){ mt[j]=-30+(j*5); }     
}
void loop() {
  i = analogRead(s);
  Serial.print("anlog=");
  Serial.print(i);
   v = map(i, 0, 1023, 0, 5000);
   v = v / 1000;
   r=v*10.0/(5.0-v);
   for(int j=0; j<28; j++){
       if(r < mr[j] && r >= mr[j+1]){
         t = map(r*1000, mr[j]*1000, mr[j+1]*1000, mt[j]*100, mt[j+1]*100);
          t = t/100;
          j = 28;
        }
   }
    Serial.print(" temp=");
    Serial.println(t); }
