object Form5: TForm5
  Left = 0
  Top = 0
  Caption = 'Form5'
  ClientHeight = 489
  ClientWidth = 752
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  TextHeight = 15
  object PaintBox1: TPaintBox
    Left = 31
    Top = -7
    Width = 345
    Height = 265
    OnMouseDown = PaintBox1MouseDown
    OnMouseMove = PaintBox1MouseMove
    OnMouseUp = PaintBox1MouseUp
    OnPaint = PaintBox1Paint
  end
  object Label1: TLabel
    Left = 320
    Top = 454
    Width = 108
    Height = 15
    Caption = 'Second player'#39's field'
  end
  object Button1: TButton
    Left = 560
    Top = 445
    Width = 113
    Height = 36
    Caption = '->start'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 200
    Top = 450
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 1
  end
end
