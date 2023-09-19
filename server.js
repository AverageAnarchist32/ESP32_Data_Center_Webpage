const express = require('express');
const axios = require('axios'); // Add Axios library to make HTTP requests
const app = express();

// Serve static files from the 'public' directory
app.use(express.static('public'));

// Endpoint to fetch ESP32 status
app.get('/status', async (req, res) => {
  try {
    // Send an HTTP GET request to the ESP32 to fetch data
    const esp32Response = await axios.get('http://ip address/data'); // Replace with your ESP32's IP and endpoint
    const esp32Data = esp32Response.data;

    // Combine the data from ESP32 into a JSON response
    const combinedData = {
      analogValue: esp32Data.analogValue,
      ledStatus: esp32Data.ledStatus,
      humidity: esp32Data.humidity, // Add humidity data from the ESP32
      temperature: esp32Data.temperature, // Add temperature data from the ESP32
    };

    res.json(combinedData);
  } catch (error) {
    console.error(error);
    res.status(500).json({ error: 'Unable to fetch data from ESP32' });
  }
});

const port = 3000;
app.listen(port, () => {
  console.log(`Node.js server is running on port ${port}`);
});
