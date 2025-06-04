using System;
using System.Net.WebSockets;
using System.Reactive.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Websocket.Client;

namespace R2D2_Remote_Control
{
    public partial class Form1 : Form
    {
        private WebsocketClient client;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string message = txtMessage.Text.Trim();
            if (client != null && client.IsRunning && !string.IsNullOrEmpty(message))
            {
                client.Send(message);
                lstLog.Items.Add("Sent: " + message);
            }
            else
            {
                lstLog.Items.Add("Not connected or message empty.");
            }
        }

        private async void btnConnect_Click(object sender, EventArgs e)
        {
            var url = new Uri("ws://192.168.1.100/ws"); // Replace with your ESP32 WebSocket address

            client = new WebsocketClient(url);
            client.ReconnectTimeout = TimeSpan.FromSeconds(30);
            client.MessageReceived
                  .Where(msg => !string.IsNullOrEmpty(msg.Text))
                  .Subscribe(msg =>
                  {
                      this.Invoke((MethodInvoker)(() =>
                      {
                          lstLog.Items.Add("Received: " + msg.Text);
                      }));
                  });

            await client.Start();
            lstLog.Items.Add("Connected to ESP32 WebSocket");
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            client?.Dispose();
        }
    }
}
