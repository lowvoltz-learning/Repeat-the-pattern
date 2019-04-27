#define column_pin_1 10
#define column_pin_2 11
#define column_pin_3 12
#define row_pin_1 9
#define row_pin_2 8
#define row_input_1 2
#define row_input_2 3
#define column_input_1 4
#define column_input_2 5
#define column_input_3 6

#include <pRNG.h>

int row_val;
int column_val;

class LED_Output
{
  public:
    pRNG prng;

  int led_output_table[2][3] = {
    {column_input_1, column_input_2, column_input_3},
    {column_input_1, column_input_2, column_input_3}
  };

  unsigned int r_generate_random_number()
  {
    unsigned int row_val_int = prng.getRndInt() % 2 + 2;
    return row_val_int;
  }

  unsigned int c_generate_random_number()
  {
    unsigned int row_val_int = prng.getRndInt() % 3 + 4;
    return row_val_int;
  }

  int led_turn_on()
  {
    pinMode(row_input_1, OUTPUT);
    pinMode(row_input_2, OUTPUT);
    pinMode(column_input_1, OUTPUT);
    pinMode(column_input_2, OUTPUT);
    pinMode(column_input_3, OUTPUT);
    int rnr = r_generate_random_number();
    int cnr = c_generate_random_number();
    digitalWrite(rnr, HIGH);
    digitalWrite(cnr, HIGH);
    delay(1000);
    digitalWrite(rnr, LOW);
    digitalWrite(cnr, LOW);
    delay(1000);
  }
 
};


// Look at struct for pinMode - coursity of Kurt :)

class Button_Input
{
  public:
    // ButtonInput Variables
    char button_items[2][3] = {
      {'1', '2', '3'},
      {'4', '5', '6'}
    };
    
    int column_pins[3] = {column_pin_1, column_pin_2, column_pin_3};
    int row_pins[2] = {row_pin_1, row_pin_2};
  
  // ButtonInput Methods
  int row_input_check()
  {
    // Defins the Pinmodes if the column and row pins
    pinMode(column_pin_1, OUTPUT);
    pinMode(column_pin_2, OUTPUT);
    pinMode(column_pin_3, OUTPUT);
    pinMode(row_pin_1, INPUT_PULLUP);
    pinMode(row_pin_2, INPUT_PULLUP);
    digitalWrite(column_pin_1, LOW);
    digitalWrite(column_pin_2, LOW);
    digitalWrite(column_pin_3, LOW);
    // Checks for row input
    while (true)
    {
      for (int i = 0; i < 2; i++)
      {
        if (digitalRead(row_pins[i]) == 0)
        {
          return i;
        }
      }
    }
  }

  int column_input_check()
  {
    pinMode(column_pin_1, INPUT_PULLUP);
    pinMode(column_pin_2, INPUT_PULLUP);
    pinMode(column_pin_3, INPUT_PULLUP);
    pinMode(row_pin_1, OUTPUT);
    pinMode(row_pin_2, OUTPUT);
    digitalWrite(row_pin_1, LOW);
    digitalWrite(row_pin_2, LOW);
    while (true)
    {
      for (int i = 0; i < 3; i++)
      {
        if (digitalRead(column_pins[i]) == 0)
        {
          return i;
        }
      }
    }
  }
  
};

LED_Output obj1;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  obj1.led_turn_on();
}
