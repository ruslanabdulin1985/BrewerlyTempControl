from django.urls import path
from . import views


urlpatterns = [
    path('', views.blink, name='my-blink'),
    path('on', views.on, name='on'),
    # path('/images/', views.blink.images, name='my-img'),
]