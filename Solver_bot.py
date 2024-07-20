from decimal import *
import math as m
import telebot
from telebot import types
bot = telebot.TeleBot('6402931382:AAElCv5ZBHUAXsMr6aCqGYAm_1V-HYWT1V0')
@bot.message_handler(commands=['start'])
def get_text_messages(message):
        markup = types.InlineKeyboardMarkup()
        first_mess = f"<b>{message.from_user.first_name}</b>, привет!\nЭто бот для решения квадратных уравнений. Выбери, что хочешь сделать"
        solve_button=types.InlineKeyboardButton(text='Решить уравнение', callback_data='solve')
        markup.add(solve_button)
        notice_button=types.InlineKeyboardButton(text = 'Прочитать справку о видах уравнений', callback_data='notice')
        markup.add(notice_button)
        instruction_button=types.InlineKeyboardButton(text = 'Открыть инструкцию', callback_data='instruction')
        markup.add(instruction_button)
        download_button = types.InlineKeyboardButton(text='Скачать консольное приложение', callback_data='download')
        markup.add(download_button)
        bot.send_message(message.chat.id, first_mess, parse_mode='html', reply_markup=markup)

@bot.callback_query_handler(func=lambda  call:True)
def response(function_call):
  if function_call.message:
     if function_call.data == "notice":
        second_mess = "Виды уравнений, которые может решить данный бот:\nax^2+bx+c=0\nax^2+bx=0\nax^2+c=0\nax^2=0\nbx+c=0\nbx=0\nc=0"
        bot.answer_callback_query(function_call.id)
        markup = types.InlineKeyboardMarkup()
        solve_button = types.InlineKeyboardButton(text='Решить уравнение', callback_data='solve')
        markup.add(solve_button)
        notice_button = types.InlineKeyboardButton(text='Прочитать справку о видах уравнений', callback_data='notice')
        markup.add(notice_button)
        instruction_button = types.InlineKeyboardButton(text='Открыть инструкцию', callback_data='instruction')
        markup.add(instruction_button)
        download_button = types.InlineKeyboardButton(text='Скачать консольное приложение', callback_data='download')
        markup.add(download_button)
        bot.send_message(function_call.message.chat.id, second_mess, parse_mode='html', reply_markup=markup)
     if function_call.data == "instruction":
        second_mess = "Для вывода меню напиши боту '/start'. Затем выбери нужную команду, кликнув на соответствующую кнопку курсором. Если ты выбрал решение уравнения, после соответствующего сообщения введи уравнение в виде 'ax^2+b+c' или любой другой формы из представленных в справке,где a, b и с - действительные числа. После получения ответов нажмите на кнопку с нужной Вам командой"
        bot.answer_callback_query(function_call.id)
        markup = types.InlineKeyboardMarkup()
        solve_button = types.InlineKeyboardButton(text='Решить уравнение', callback_data='solve')
        markup.add(solve_button)
        notice_button = types.InlineKeyboardButton(text='Прочитать справку о видах уравнений', callback_data='notice')
        markup.add(notice_button)
        instruction_button = types.InlineKeyboardButton(text='Открыть инструкцию', callback_data='instruction')
        markup.add(instruction_button)
        download_button = types.InlineKeyboardButton(text='Скачать консольное приложение', callback_data='download')
        markup.add(download_button)
        bot.send_message(function_call.message.chat.id, second_mess, parse_mode='html', reply_markup=markup)
     if function_call.data == "download":
        second_mess = "Держи ссылку на Яндекс Диск с приложением. Благодарим за выбор нашего приложения!"
        bot.answer_callback_query(function_call.id)
        markup = types.InlineKeyboardMarkup()
        markup.add(types.InlineKeyboardButton("Перейти в Яндекс Диск",url="https://disk.yandex.ru/d/PjGmqt8sVYlYfg"))
        solve_button = types.InlineKeyboardButton(text='Решить уравнение', callback_data='solve')
        markup.add(solve_button)
        notice_button = types.InlineKeyboardButton(text='Прочитать справку о видах уравнений', callback_data='notice')
        markup.add(notice_button)
        instruction_button = types.InlineKeyboardButton(text='Открыть инструкцию', callback_data='instruction')
        markup.add(instruction_button)
        download_button = types.InlineKeyboardButton(text='Скачать консольное приложение', callback_data='download')
        markup.add(download_button)
        bot.send_message(function_call.message.chat.id, second_mess, parse_mode='html', reply_markup=markup)
     if function_call.data == "solve":
        msg = bot.send_message(function_call.message.chat.id,"Введите уравнение в формате ax^2+bx+c, где a, b и c - любые действительные числа")
        bot.register_next_step_handler(msg, solver)


def solver(message):
    alpha=['0','1','2','3','4','5','6','7','8','9','.']
    equation=message.text
    equation=equation.lower()
    equation=equation.replace('х','x')
    equation=equation.replace(' ','')
    buf=equation
    a=0
    b=0
    c=0
    flaga=1
    flagb=1
    flagc=1
    if (equation.count('x^2')!=0):
        astr=''
        counter=0
        minus=0
        if equation[0]=='-':
            minus=1
            equation=equation[1:]
        if equation[0]=="+":
            equation=equation[1:]
        for i in range (0,equation.find('^')-1):
            counter+=1
            if equation[i] in alpha:
                astr+=equation[i]
            else:
                flaga=0
                flagb=0
                flagc=0
                break
        if (flaga==1 and len(astr)!=0):
            a=float(Decimal(astr))
            if minus==1:
                a*=-1
        elif (flaga==1 and len(astr)==0):
            a=1
            if minus==1:
                a*=-1
        buf=equation[(counter+3):]
    if (buf.count('x')!=0 and flaga!=0):
        bstr=''
        counter=0
        minus=0
        if buf[0]=='-':
            minus=1
            buf=buf[1:]
        if buf[0]=='+':
            buf=buf[1:]
        for i in range (0,buf.find('x')):
            counter+=1
            if buf[i] in alpha:
                bstr+=buf[i]
            else:
                flaga=0
                flagb=0
                flagc=0
                break
        if (flagb==1 and len(bstr)!=0):
            b=float(Decimal(bstr))
            if minus==1:
                b*=-1
        elif (flagb==1 and len(bstr)==0):
            b=1
            if minus==1:
                b*=-1
        buf=buf[(counter+1):]
    if (flaga!=0 and flagb!=0):
        cstr=''
        if buf[0]=='+':
            buf=buf[1:]
        for i in range (0,len(buf)):
            if buf[i] in alpha:
                cstr+=buf[i]
            else:
                flagc=0
                break
        if (flagc==1 and len(cstr)!=0):
            c=float(Decimal(cstr))
    msg=''
    if (flaga+flagb+flagc!=3):
        msg='Уравнение введено неверно'
    else:
        if (flaga==flagb==flagc==1 and a!=0 and b!=0 and c!=0):
            msg=standeq(a,b,c)
        elif (flaga==flagb==flagc==1 and a==0 and b!=0 and c!=0):
            msg=EWoA(b,c)
        elif (flaga==flagb==flagc==1 and a!=0 and b==0 and c!=0):
            msg=EWoB(a,c)
        elif (flaga==flagb==flagc==1 and a==0 and b==0):
            msg=EWC(c)
        elif (flaga==flagb==flagc==1 and ((a!=0 and b==0 and c==0) or (a==0 and b!=0 and c==0))):
            msg=EWAoB()
        elif (flaga==flagb==flagc==1 and a!=0 and b!=0 and c==0):
            msg=EWoC(a,b)
    markup = types.InlineKeyboardMarkup()
    solve_button = types.InlineKeyboardButton(text='Решить уравнение', callback_data='solve')
    markup.add(solve_button)
    notice_button = types.InlineKeyboardButton(text='Прочитать справку о видах уравнений', callback_data='notice')
    markup.add(notice_button)
    instruction_button = types.InlineKeyboardButton(text='Открыть инструкцию', callback_data='instruction')
    markup.add(instruction_button)
    download_button = types.InlineKeyboardButton(text='Скачать консольное приложение', callback_data='download')
    markup.add(download_button)
    bot.send_message(message.chat.id, msg, parse_mode='html', reply_markup=markup)



def standeq(a,b,c):
    disc=b**2-a*c*4
    if disc>=0:
        x1=(-b-m.sqrt(disc))/(2*a)
        x2=(-b+m.sqrt(disc))/(2*a)
        if x1!=x2:
            answer=str(x1)+'   '+str(x2)
        else:
            answer=str(x1)
    else:
        answer="Только комплексные корни"
    return answer


def EWoA(b,c):
    answer=str(-c/b)
    return answer

def EWC(c):
    if (c==0):
        answer='Х любой'
    else:
        answer='Уравнение неверно'
    return answer

def EWoB(a,c):
    if (c*a)>0:
        answer='Только комплексные корни'
    else:
        x1=-m.sqrt(-c/a)
        x2=m.sqrt(-c/a)
        if x1!=x2:
            answer=str(x1)+'   '+str(x2)
        else:
            answer=str(x1)
    return answer

def EWAoB():
    answer='0'
    return answer

def EWoC(a,b):
    x=(-b/a)
    answer='0   '+str(x)
    return answer

bot.polling(none_stop=True, interval=0)