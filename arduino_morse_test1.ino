// Define the digital pin connected to the LED, this works with the built in LED so you don't need a breasboard
const int ledPin = 13;

// Morse code representation of the letters and numbers
const String morseCode[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
  "..-", "...-", ".--", "-..-", "-.--", "--..",
  ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

void setup() {
  // Initialise the serial communication
  Serial.begin(9600);
  
  // Set the LED pin as output
  pinMode(ledPin, OUTPUT);
  
  // Briefly blink the LED to indicate the initialisation
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Prompt the user to enter their name
  Serial.println("Enter your name:");
  
  while (Serial.available() == 0) {
    // Wait for user input
  }
  
  // Read the user's name from the serial monitor
  String name = Serial.readString();
  
  Serial.println(name);
  
  // Remove any whitespace characters
  name.trim();
  
  // Convert the name to uppercase
  name.toUpperCase();
  
  // Iterate over each character in the name
  for (int i = 0; i < name.length(); i++) {
    char character = name.charAt(i);
    
    if (character == ' ') {
      // Delay for a space between words
      delay(700);
    } else {
      // Convert the character to Morse code
      int index = character - 'A';
      
      if (index >= 0 && index < 26) {
        String morse = morseCode[index];
        
        // Blink the LED based on the Morse code
        for (int j = 0; j < morse.length(); j++) {
          if (morse.charAt(j) == '.') {
            dot();
          } else if (morse.charAt(j) == '-') {
            dash();
          }
          
          // Delay between dots/dashes within a character
          delay(200);
        }
      }
    }
    
    // delay between characters
    delay(400);
  }
  
  // Clear the name variable
  name = "";
}

//this is the function to turn on the LED for a dot
void dot() {
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
}

//this is the function to turn on the LED for a dot
void dash() {
  digitalWrite(ledPin, HIGH);
  delay(600);
  digitalWrite(ledPin, LOW);
}
