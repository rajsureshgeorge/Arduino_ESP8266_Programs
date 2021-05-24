//Basic Program For LED controllin using a Switch
int c=0,f=0;

void intr();

void setup() 
{
  
  // put your setup code here, to run once:
  pinMode(16,OUTPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);
attachInterrupt(digitalPinToInterrupt(12),intrp,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  
if(f==1)
{
    digitalWrite(16,HIGH);
    
}
else
{
    digitalWrite(16,LOW);
    
}
  

}

void intrp()
{
  f=!f;
  Serial.println("intrupt");

  if(f==1)
{
    Serial.println("LED is on");
}
else
{
  Serial.println("LED is off");
  }
  }

}
