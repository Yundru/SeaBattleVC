object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 690
  ClientWidth = 1068
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object PaintBox1: TPaintBox
    Left = 56
    Top = 96
    Width = 345
    Height = 265
    OnMouseDown = PaintBox1MouseDown
  end
  object PaintBox2: TPaintBox
    Left = 592
    Top = 96
    Width = 345
    Height = 265
    OnMouseDown = PaintBox2MouseDown
  end
  object Label1: TLabel
    Left = 504
    Top = 24
    Width = 41
    Height = 15
    Caption = 'Player 1'
  end
end
