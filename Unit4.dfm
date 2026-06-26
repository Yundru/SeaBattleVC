object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Form4'
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
  end
  object PaintBox2: TPaintBox
    Left = 591
    Top = 96
    Width = 345
    Height = 265
    OnMouseDown = PaintBox2MouseDown
    OnMouseUp = PaintBox2MouseUp
  end
  object Label1: TLabel
    Left = 192
    Top = 32
    Width = 41
    Height = 15
    Caption = 'Player 1'
  end
  object Label2: TLabel
    Left = 760
    Top = 40
    Width = 32
    Height = 15
    Caption = 'Robot'
  end
end
