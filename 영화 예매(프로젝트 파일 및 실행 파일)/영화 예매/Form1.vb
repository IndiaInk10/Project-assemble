Public Class Form1
    Dim 나이영화이름1 As String
    Dim 영화예매율1 As String
    Dim 영화개요1 As String
    Dim 영화감독1 As String
    Dim 영화출연진1 As String
    Dim 나이영화이름2 As String
    Dim 영화예매율2 As String
    Dim 영화개요2 As String
    Dim 영화감독2 As String
    Dim 영화출연진2 As String
    Dim 나이영화이름3 As String
    Dim 영화예매율3 As String
    Dim 영화개요3 As String
    Dim 영화감독3 As String
    Dim 영화출연진3 As String
    Dim 상영영화정보엑셀1 As Object
    Dim 상영영화정보엑셀파일1 As Object
    Private Sub CGVURL_Click(sender As Object, e As EventArgs) Handles CGVURL.Click
        If MsgBox("CGV 영화예매 사이트로 이동하시겠습니까?", vbQuestion + vbYesNo, "재차확인") = vbYes Then
            Shell("explorer http://www.cgv.co.kr/ticket/")
        End If
    End Sub

    Private Sub MEGAURL_Click(sender As Object, e As EventArgs) Handles MEGAURL.Click
        If MsgBox("MEGABOX 영화예매 사이트로 이동하시겠습니까?", vbQuestion + vbYesNo, "재차확인") = vbYes Then
            Shell("explorer http://www.megabox.co.kr/")
        End If
    End Sub

    Private Sub LOTTEURL_Click(sender As Object, e As EventArgs) Handles LOTTEURL.Click
        If MsgBox("LOTTE CINEMA 영화예매 사이트로 이동하시겠습니까?", vbQuestion + vbYesNo, "재차확인") = vbYes Then
            Shell("explorer http://www.lottecinema.co.kr/LCHS/Contents/ticketing/ticketing.aspx")
        End If
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        상영영화정보엑셀1 = CreateObject("excel.application")

        상영영화정보엑셀파일1 = 상영영화정보엑셀1.workbooks.open("D:\상영영화순위")

        나이영화이름1 = 상영영화정보엑셀파일1.sheets(1).cells(112, 1).value
        영화예매율1 = 상영영화정보엑셀파일1.sheets(1).cells(117, 1).value
        영화개요1 = 상영영화정보엑셀파일1.sheets(1).cells(119, 1).value
        영화감독1 = 상영영화정보엑셀파일1.sheets(1).cells(121, 1).value
        영화출연진1 = 상영영화정보엑셀파일1.sheets(1).cells(123, 1).value
        AgeName1.Text = "[" + 나이영화이름1 + "]"
        Reserve1.Text = "예매율: " + 영화예매율1 + "*100"
        Outline1.Text = "개요: " + 영화개요1
        Director1.Text = "감독: " + 영화감독1
        Appear1.Text = "출연진: " + 영화출연진1

        나이영화이름2 = 상영영화정보엑셀파일1.sheets(1).cells(127, 1).value
        영화예매율2 = 상영영화정보엑셀파일1.sheets(1).cells(132, 1).value
        영화개요2 = 상영영화정보엑셀파일1.sheets(1).cells(134, 1).value
        영화감독2 = 상영영화정보엑셀파일1.sheets(1).cells(136, 1).value
        영화출연진2 = 상영영화정보엑셀파일1.sheets(1).cells(138, 1).value
        AgeName2.Text = "[" + 나이영화이름2 + "]"
        Reserve2.Text = "예매율: " + 영화예매율2 + "*100"
        Outline2.Text = "개요: " + 영화개요2
        Director2.Text = "감독: " + 영화감독2
        Appear2.Text = "출연진: " + 영화출연진2

        나이영화이름3 = 상영영화정보엑셀파일1.sheets(1).cells(142, 1).value
        영화예매율3 = 상영영화정보엑셀파일1.sheets(1).cells(147, 1).value
        영화개요3 = 상영영화정보엑셀파일1.sheets(1).cells(149, 1).value
        영화감독3 = 상영영화정보엑셀파일1.sheets(1).cells(151, 1).value
        영화출연진3 = 상영영화정보엑셀파일1.sheets(1).cells(153, 1).value
        AgeName3.Text = "[" + 나이영화이름3 + "]"
        Reserve3.Text = "예매율: " + 영화예매율3 + "*100"
        Outline3.Text = "개요: " + 영화개요3
        Director3.Text = "감독: " + 영화감독3
        Appear3.Text = "출연진: " + 영화출연진3

        상영영화정보엑셀파일1.close()
    End Sub
End Class
