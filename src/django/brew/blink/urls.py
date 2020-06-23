from django.urls import path
from . import views


urlpatterns = [
    path('', views.blink, name='my-blink'),
]