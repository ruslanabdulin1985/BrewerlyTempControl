from django.shortcuts import render
from django.http import HttpResponse
from . import models
# Create your views here.



def blink(request):
    #my_str = models.getData()
    my_str = "random string"
    content = {'m_string' : my_str}
    return render(request, 'blink/blink.html', content)

# def images(request):
#     my_str = models.getData()
#     content = {'m_string' : my_str}
#     return render(request, 'blink/index.html', content)

def on(request):
    #my_str = models.getData()
    
    models.turnOn()
    return render(request, 'blink/on.html')
    #models.turnOn()

