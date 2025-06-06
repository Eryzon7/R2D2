namespace R2D2_Remote_Control
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            button1 = new Button();
            lstLog = new ListBox();
            btnConnect = new Button();
            txtMessage = new TextBox();
            msg_logs_label = new Label();
            SuspendLayout();
            // 
            // button1
            // 
            button1.Location = new Point(67, 88);
            button1.Name = "button1";
            button1.Size = new Size(75, 23);
            button1.TabIndex = 0;
            button1.Text = "send msg";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // lstLog
            // 
            lstLog.FormattingEnabled = true;
            lstLog.ItemHeight = 15;
            lstLog.Location = new Point(426, 89);
            lstLog.Name = "lstLog";
            lstLog.Size = new Size(120, 94);
            lstLog.TabIndex = 1;
            // 
            // btnConnect
            // 
            btnConnect.Location = new Point(67, 358);
            btnConnect.Name = "btnConnect";
            btnConnect.Size = new Size(75, 23);
            btnConnect.TabIndex = 3;
            btnConnect.Text = "Connect";
            btnConnect.UseVisualStyleBackColor = true;
            btnConnect.Click += btnConnect_Click;
            // 
            // txtMessage
            // 
            txtMessage.Location = new Point(184, 89);
            txtMessage.Name = "txtMessage";
            txtMessage.Size = new Size(100, 23);
            txtMessage.TabIndex = 4;
            // 
            // msg_logs_label
            // 
            msg_logs_label.AutoSize = true;
            msg_logs_label.Location = new Point(426, 59);
            msg_logs_label.Name = "msg_logs_label";
            msg_logs_label.Size = new Size(55, 15);
            msg_logs_label.TabIndex = 5;
            msg_logs_label.Text = "msg logs";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(msg_logs_label);
            Controls.Add(txtMessage);
            Controls.Add(btnConnect);
            Controls.Add(lstLog);
            Controls.Add(button1);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button button1;
        private ListBox lstLog;
        private Button btnConnect;
        private TextBox txtMessage;
        private Label msg_logs_label;
    }
}
