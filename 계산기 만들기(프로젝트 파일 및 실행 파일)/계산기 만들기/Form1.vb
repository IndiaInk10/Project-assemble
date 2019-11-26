Public Class Form1
    Dim 입력값1 As Integer
    Dim 입력값2 As Integer
    Dim 결과값 As Integer

    Private Sub Rectangle_Click(sender As Object, e As EventArgs) Handles Rectangle.Click

        입력값1 = Val(Length.Text)

        입력값2 = Val(Height.Text)

        결과값 = 입력값1 * 입력값2

        Area.Text = 결과값
    End Sub

    Private Sub Triangle_Click(sender As Object, e As EventArgs) Handles Triangle.Click

        입력값1 = Val(Length.Text)

        입력값2 = Val(Height.Text)

        결과값 = (입력값1 * 입력값2) / 2

        Area.Text = 결과값
    End Sub

    Private Sub Circle_Click(sender As Object, e As EventArgs) Handles Circle.Click

        입력값1 = Val(Length.Text)

        결과값 = (입력값1 * 입력값1)

        Area.Text = 결과값 & "π"
    End Sub

    Private Sub Trapeze_Click(sender As Object, e As EventArgs) Handles Trapeze.Click

        입력값1 = Val(Length.Text)

        입력값2 = Val(Height.Text)

        결과값 = (입력값1 * 입력값2) / 2

        Area.Text = 결과값
    End Sub

    Private Sub Rhombus_Click(sender As Object, e As EventArgs) Handles Rhombus.Click

        입력값1 = Val(Length.Text)

        입력값2 = Val(Height.Text)

        결과값 = (입력값1 * 입력값2) / 2

        Area.Text = 결과값
    End Sub

    Private Sub Reset_Click(sender As Object, e As EventArgs) Handles Reset.Click

        Height.Text = " "
        Length.Text = " "
        Area.Text = " "

    End Sub
End Class
