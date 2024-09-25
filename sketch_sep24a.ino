#include <WiFi.h>
#include <WebServer.h>

#define TRIG_PIN 12
#define ECHO_PIN 14

WebServer server(80);

void setup() {
    Serial.begin(115200);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    
    // Connect to Wi-Fi
    WiFi.begin("vivo", "Aadesh123");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
    
    // Set up route for distance measurement
    server.on("/distance", HTTP_GET, handleDistance);
    server.begin();
    Serial.println("Server started");
}

void loop() {
    server.handleClient(); // Handle incoming client requests

    // Existing distance measurement code
    long duration;
    int distance;

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    
    duration = pulseIn(ECHO_PIN, HIGH);
    distance = duration * 0.034 / 2;

    // Print distance to serial

    Serial.print(WiFi.localIP());
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    
    // Small delay for stability
    delay(500);
}

void handleDistance() {
    long duration;
    int distance;

    // Measure distance
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    
    duration = pulseIn(ECHO_PIN, HIGH);
    distance = duration * 0.034 / 2;

    // Create JSON response
    String json = String("{\"distance\":") + distance + "}";
    server.sendHeader("Access-Control-Allow-Origin","*");
    server.send(200, "application/json", json);
}
