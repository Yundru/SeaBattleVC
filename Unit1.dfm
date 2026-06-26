object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 338
  ClientWidth = 364
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 32
    Top = 128
    Width = 89
    Height = 57
    Caption = 'Play (pl1/pl2)'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 224
    Top = 128
    Width = 89
    Height = 57
    Caption = 'Statistic'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button4: TButton
    Left = 32
    Top = 216
    Width = 89
    Height = 57
    Caption = 'Play (robot)'
    TabOrder = 2
    OnClick = Button4Click
  end
end
