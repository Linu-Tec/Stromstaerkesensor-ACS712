int Sensor = A0; // Der Stromstärkesensor wird am Pin A0 (Analog "0") angeschlossen.
int VpA = 100; // Millivolt pro Ampere (185 für 05A Modul & 100 für 20A Modul & 66 für 30A Modul)
int sensorwert= 0;
int Nullpunkt = 2500; // Spannung in mV bei dem keine Stromstärke vorhanden ist
double SensorSpannung = 0;
double Ampere = 0;

void setup(){
  Serial.begin(9600); // Serielle Verbindung starten, damit die Daten am Seriellen Monitor angezeigt werden.
}

void loop(){
  sensorwert = analogRead(Sensor);
  SensorSpannung = (sensorwert / 1024.0) * 5000; // Hier wird der Messwert in den Spannungswert am Sensor umgewandelt.
  Ampere = ((SensorSpannung - Nullpunkt) / VpA); // Im zweiten Schritt wird hier die Stromstärke berechnet.
  
  // Ausgabe der Ergebnisse am Seriellen Monitor
  Serial.print("Sensorwert = " ); // Ausgabe des reinen Sensorwertes
  Serial.print(sensorwert); 
  Serial.print("\t Sensorspannung in mV = "); // Zeigt die Sensorspannung an
  Serial.print(SensorSpannung,3); // Die "3" hinter dem Komma erzeugt drei Nachkommastellen
  Serial.print("\t Ampere = "); // shows the voltage measured 
  Serial.println(Ampere,3); // Die "3" hinter dem Komma erzeugt drei Nachkommastellen
  delay(1000); 
}

// Nach der Programmierung wird der Serielle Monitor geöffnet. Dort werden nun abhängig von der gemessenen Stromstärke die Messwerte angezeigt.
