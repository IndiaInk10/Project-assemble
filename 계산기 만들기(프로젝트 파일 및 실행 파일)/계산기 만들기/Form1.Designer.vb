<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form은 Dispose를 재정의하여 구성 요소 목록을 정리합니다.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Windows Form 디자이너에 필요합니다.
    Private components As System.ComponentModel.IContainer

    '참고: 다음 프로시저는 Windows Form 디자이너에 필요합니다.
    '수정하려면 Windows Form 디자이너를 사용하십시오.  
    '코드 편집기에서는 수정하지 마세요.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form1))
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Length = New System.Windows.Forms.TextBox()
        Me.Height = New System.Windows.Forms.TextBox()
        Me.Area = New System.Windows.Forms.TextBox()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Triangle = New System.Windows.Forms.Button()
        Me.Rectangle = New System.Windows.Forms.Button()
        Me.Trapeze = New System.Windows.Forms.Button()
        Me.Rhombus = New System.Windows.Forms.Button()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.Label9 = New System.Windows.Forms.Label()
        Me.Circle = New System.Windows.Forms.Button()
        Me.Reset = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("맑은 고딕", 20.0!)
        Me.Label1.Location = New System.Drawing.Point(22, 26)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(71, 37)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "밑변"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Font = New System.Drawing.Font("맑은 고딕", 20.0!)
        Me.Label2.Location = New System.Drawing.Point(22, 209)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(71, 37)
        Me.Label2.TabIndex = 1
        Me.Label2.Text = "높이"
        '
        'Length
        '
        Me.Length.Font = New System.Drawing.Font("굴림", 20.0!)
        Me.Length.Location = New System.Drawing.Point(25, 78)
        Me.Length.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.Length.Name = "Length"
        Me.Length.Size = New System.Drawing.Size(116, 38)
        Me.Length.TabIndex = 2
        '
        'Height
        '
        Me.Height.Font = New System.Drawing.Font("굴림", 20.0!)
        Me.Height.Location = New System.Drawing.Point(27, 261)
        Me.Height.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.Height.Name = "Height"
        Me.Height.Size = New System.Drawing.Size(114, 38)
        Me.Height.TabIndex = 3
        '
        'Area
        '
        Me.Area.Font = New System.Drawing.Font("굴림", 20.0!)
        Me.Area.Location = New System.Drawing.Point(488, 520)
        Me.Area.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.Area.Name = "Area"
        Me.Area.Size = New System.Drawing.Size(156, 38)
        Me.Area.TabIndex = 4
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Font = New System.Drawing.Font("맑은 고딕", 20.0!)
        Me.Label3.Location = New System.Drawing.Point(483, 466)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(71, 37)
        Me.Label3.TabIndex = 5
        Me.Label3.Text = "넓이"
        '
        'Triangle
        '
        Me.Triangle.BackgroundImage = CType(resources.GetObject("Triangle.BackgroundImage"), System.Drawing.Image)
        Me.Triangle.Font = New System.Drawing.Font("맑은 고딕", 15.0!, System.Drawing.FontStyle.Bold)
        Me.Triangle.Location = New System.Drawing.Point(27, 344)
        Me.Triangle.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.Triangle.Name = "Triangle"
        Me.Triangle.Size = New System.Drawing.Size(122, 104)
        Me.Triangle.TabIndex = 6
        Me.Triangle.Text = "삼각형"
        Me.Triangle.TextAlign = System.Drawing.ContentAlignment.BottomCenter
        Me.Triangle.UseVisualStyleBackColor = True
        '
        'Rectangle
        '
        Me.Rectangle.BackgroundImage = CType(resources.GetObject("Rectangle.BackgroundImage"), System.Drawing.Image)
        Me.Rectangle.Font = New System.Drawing.Font("맑은 고딕", 15.0!, System.Drawing.FontStyle.Bold)
        Me.Rectangle.Location = New System.Drawing.Point(169, 344)
        Me.Rectangle.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.Rectangle.Name = "Rectangle"
        Me.Rectangle.Size = New System.Drawing.Size(145, 219)
        Me.Rectangle.TabIndex = 7
        Me.Rectangle.Text = "직사각형," & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10) & "평행사변형"
        Me.Rectangle.TextAlign = System.Drawing.ContentAlignment.BottomCenter
        Me.Rectangle.UseVisualStyleBackColor = True
        '
        'Trapeze
        '
        Me.Trapeze.BackColor = System.Drawing.SystemColors.Control
        Me.Trapeze.BackgroundImage = CType(resources.GetObject("Trapeze.BackgroundImage"), System.Drawing.Image)
        Me.Trapeze.Font = New System.Drawing.Font("맑은 고딕", 15.0!, System.Drawing.FontStyle.Bold)
        Me.Trapeze.Location = New System.Drawing.Point(337, 344)
        Me.Trapeze.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.Trapeze.Name = "Trapeze"
        Me.Trapeze.Size = New System.Drawing.Size(122, 104)
        Me.Trapeze.TabIndex = 8
        Me.Trapeze.Text = "사다리꼴"
        Me.Trapeze.TextAlign = System.Drawing.ContentAlignment.BottomCenter
        Me.Trapeze.UseVisualStyleBackColor = False
        '
        'Rhombus
        '
        Me.Rhombus.BackgroundImage = CType(resources.GetObject("Rhombus.BackgroundImage"), System.Drawing.Image)
        Me.Rhombus.Font = New System.Drawing.Font("맑은 고딕", 15.0!, System.Drawing.FontStyle.Bold)
        Me.Rhombus.Location = New System.Drawing.Point(337, 461)
        Me.Rhombus.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.Rhombus.Name = "Rhombus"
        Me.Rhombus.Size = New System.Drawing.Size(122, 101)
        Me.Rhombus.TabIndex = 9
        Me.Rhombus.Text = "마름모"
        Me.Rhombus.TextAlign = System.Drawing.ContentAlignment.BottomCenter
        Me.Rhombus.UseVisualStyleBackColor = True
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Font = New System.Drawing.Font("맑은 고딕", 15.0!)
        Me.Label4.Location = New System.Drawing.Point(179, 26)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(84, 28)
        Me.Label4.TabIndex = 10
        Me.Label4.Text = "[도움말]"
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Font = New System.Drawing.Font("맑은 고딕", 15.0!)
        Me.Label5.Location = New System.Drawing.Point(179, 69)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(460, 56)
        Me.Label5.TabIndex = 11
        Me.Label5.Text = "1. 사다리꼴의 경우 (밑변) 부분에 (윗변+아래변)을" & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10) & "   한 값을 입력"
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Font = New System.Drawing.Font("맑은 고딕", 15.0!)
        Me.Label6.Location = New System.Drawing.Point(179, 134)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(453, 112)
        Me.Label6.TabIndex = 12
        Me.Label6.Text = "2. 마름모의 경우 (밑변) 부분에" & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10) & "   (두 대각선 a, b 중 하나의 길이)를 입력" & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10) & "   (밑변) 부분에 (대각선 a의 길이)를 입력했다면" &
    ", " & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10) & "   (높이) 부분에 (대각선 b의 길이)를 입력"
        '
        'Label9
        '
        Me.Label9.AutoSize = True
        Me.Label9.Font = New System.Drawing.Font("맑은 고딕", 15.0!)
        Me.Label9.Location = New System.Drawing.Point(184, 258)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(455, 56)
        Me.Label9.TabIndex = 15
        Me.Label9.Text = "3. 원의 경우 밑변 부분만 입력하고 (밑변) 부분에 " & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10) & "   (반지름)을 입력"
        '
        'Circle
        '
        Me.Circle.BackgroundImage = CType(resources.GetObject("Circle.BackgroundImage"), System.Drawing.Image)
        Me.Circle.Font = New System.Drawing.Font("맑은 고딕", 15.0!, System.Drawing.FontStyle.Bold)
        Me.Circle.Location = New System.Drawing.Point(27, 461)
        Me.Circle.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.Circle.Name = "Circle"
        Me.Circle.Size = New System.Drawing.Size(122, 104)
        Me.Circle.TabIndex = 16
        Me.Circle.Text = "원"
        Me.Circle.UseVisualStyleBackColor = True
        '
        'Reset
        '
        Me.Reset.BackColor = System.Drawing.SystemColors.GradientInactiveCaption
        Me.Reset.Font = New System.Drawing.Font("맑은 고딕", 15.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(129, Byte))
        Me.Reset.Location = New System.Drawing.Point(488, 344)
        Me.Reset.Name = "Reset"
        Me.Reset.Size = New System.Drawing.Size(151, 104)
        Me.Reset.TabIndex = 17
        Me.Reset.Text = "초기화"
        Me.Reset.UseVisualStyleBackColor = False
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 15.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(674, 594)
        Me.Controls.Add(Me.Reset)
        Me.Controls.Add(Me.Circle)
        Me.Controls.Add(Me.Label9)
        Me.Controls.Add(Me.Label6)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Rhombus)
        Me.Controls.Add(Me.Trapeze)
        Me.Controls.Add(Me.Rectangle)
        Me.Controls.Add(Me.Triangle)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Area)
        Me.Controls.Add(Me.Height)
        Me.Controls.Add(Me.Length)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Font = New System.Drawing.Font("맑은 고딕", 9.0!)
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.Name = "Form1"
        Me.Text = "도형의 넓이 계산기"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Length As TextBox
    Friend WithEvents Height As TextBox
    Friend WithEvents Area As TextBox
    Friend WithEvents Label3 As Label
    Friend WithEvents Triangle As Button
    Friend WithEvents Rectangle As Button
    Friend WithEvents Trapeze As Button
    Friend WithEvents Rhombus As Button
    Friend WithEvents Label4 As Label
    Friend WithEvents Label5 As Label
    Friend WithEvents Label6 As Label
    Friend WithEvents Label9 As Label
    Friend WithEvents Circle As Button
    Friend WithEvents Reset As Button
End Class
