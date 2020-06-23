from django.shortcuts import render
from django.http import HttpResponse
from . import models
# Create your views here.

my_str = models.getData()

def blink(request):
    content = {'m_string' : my_str}
    return render(request, 'blink/blink.html', content)

