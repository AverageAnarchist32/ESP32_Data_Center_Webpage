const express = require('express');
const axios = require('axios'); // Add Axios library to make HTTP requests
const app = express();

// Serve static files from the 'public' directory
app.use(express.static('public'));

// Endpoint to fetch ESP32 status
app.get('/status', async (req, res) => {
  try {
    // Send an HTTP GET request to the ESP32 to fetch data
    const esp32Response = await axios.get('http://192.168.1.114/data'); // Replace with your ESP32's IP and endpoint
    const esp32Data = esp32Response.data;

    res.json(esp32Data);
  } catch (error) {
    console.error(error);
    res.status(500).json({ error: 'Unable to fetch data from ESP32' });
  }
});

const port = 3000;
app.listen(port, () => {
  console.log(`Node.js server is running on port ${port}`);
});
